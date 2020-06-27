#pragma once

#include <vector>

#include "observer.hpp"

class Time : public Observer {
public:
    Time();
    virtual void nextDay() = 0;
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
    size_t getElapsedTime() const;
    Time& operator ++();

    size_t getTimeElapsed() const { return timeElapsed_; };
    Observer& getObserver(Observer* obs);

private:
    size_t timeElapsed_;
    std::vector<Observer*> observers_;  
};