#include "Time.hpp"

#include <algorithm>

Time& Time::operator++() {
    ++_time_elapsed;

    for (const auto& obs : _observers) {
        obs->NextDay();
    }

    return *this;
}
