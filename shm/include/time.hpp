// How to use class Time and Observer with Your class:
// #include "time.hpp"
// class Your : Observer {
// public:
//     Your(Time* time) : time_(time) {
//         time_->addObserver(this);
//     }
//     void nextDay() override {
//         // Some code here
//     }
// private:
//     Time* time_;
// };
//
// int main() {
//     Time* time = new Time(100);
//     ++(*time); // or
//     (*time)++;
//     delete time;
// }

#pragma once

#include <list>

class Observer {
public:
    virtual void nextDay() = 0;
    virtual ~Observer(){};
};

class Time {
public:
    Time(){};
    explicit Time(size_t game_days)
        : time_elapsed_(game_days){};
    void addObserver(Observer* obs) {
        observers_.push_back(obs);
    }
    void removeObserver(Observer* obs) {
        observers_.remove(obs);
    }
    size_t getElapsedTime() const {
        return time_elapsed_;
    }
    // Prefix increment operator (decrement elapsed time)
    Time& operator++() {
        time_elapsed_--;
        auto it = observers_.begin();
        while (it != observers_.end()) {
            (*it)->nextDay();
            ++it;
        }
        return *this;
    }
    // Postfix increment operator (decrement elapsed time)
    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

private:
    std::list<Observer*> observers_;
    size_t time_elapsed_;
};
