#include "Time.hpp"

#include <algorithm>

Time& Time::operator++() {
    ++_timeElapsed;

    for (const auto& obs : _observers) {
        obs->nextDay();
    }

    return *this;
}
