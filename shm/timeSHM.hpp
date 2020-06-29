#pragma once

#include <vector>

#include "observer.hpp"

class Time {
public:
    Time();

    bool findObserver(Observer* obs);
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);

    size_t getElapsedTime() const;

    Time& operator++();

private:
    size_t timeElapsed_;
    std::vector<Observer*> observers_;  
};