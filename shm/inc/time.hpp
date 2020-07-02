#pragma once

#include "observer.hpp"
#include <vector>

class Time {
public:
    Time();

    void AddObserver(Observer *obs);
    void RemoveObserver(Observer *obs);
    size_t GetElapsedTime() const {return time_elapsed_; }
    Time& operator++();

private:
    size_t time_elapsed_{};
    std::vector<Observer*> observers_;
    
    void notify();
};
