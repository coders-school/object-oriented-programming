// How to use class Time and Observer with Your class:
// #include "time.hpp"
// class Your : Observer {
// public:
//     Your(Time* time) : time_(time) {
//         time_->addObserver(this);
//     }
//     ~Your() {
//         time_->removeObserver(this);
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
    Time();
    Time(int game_days);
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
    size_t getElapsedTime() const;
    // Prefix increment operator (decrement elapsed time)
    Time& operator++();
    // Postfix increment operator (decrement elapsed time)
    Time operator++(int);

private:
    std::list<Observer*> observers_;
    size_t time_elapsed_;
};
