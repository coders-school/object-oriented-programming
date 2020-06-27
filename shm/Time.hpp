#pragma once

#include <cstddef>
#include <vector>

#include "Observer.hpp"

class Time {
public:
    Time& operator++();
    size_t GetTimeElpased() const { return _timeElapsed; }

private:
    size_t _timeElapsed;
    std::vector<Observer*> _observers;
};
