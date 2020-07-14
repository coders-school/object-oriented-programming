#pragma once

#include <vector>

class Time {
public:
    class Observer {
    public:
        virtual void nextDay() = 0;
        virtual ~Observer(){};
    };

    Time();
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
    size_t getElapsedTime() const;
    Time& operator++();

private:
    size_t timeElapsed_;
    std::vector<Observer*> observers_;
};
