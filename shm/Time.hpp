#pragma once

#include <cstddef>
#include <list>

#include "Observer.hpp"

class Time {
public:
    Time& operator++();
    size_t getTimeElpased() const { return _timeElapsed; }
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);

private:
    size_t _timeElapsed;
    std::list<Observer*> _observers;
};
