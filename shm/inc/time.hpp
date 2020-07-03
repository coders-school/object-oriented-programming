#pragma once

#include "observer.hpp"
#include <vector>

class Time {
public:
    Time() = default;

    void addObserver(Observer *obs);
    void removeObserver(Observer *obs);
    size_t getElapsedTime() const {return time_elapsed_; }
    Time& operator++();

private:
    size_t time_elapsed_{};
    std::vector<Observer*> observers_;
    
    void notify();
};
