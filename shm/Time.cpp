#include "Time.hpp"

#include <algorithm>

Time& Time::operator++() {
    ++_timeElapsed;

    for (const auto& obs : _observers) {
        obs->nextDay();
    }

    return *this;
}

void Time::addObserver(Observer* observer) {
    _observers.push_back(observer);
}

void Time::removeObserver(Observer* observer) {
    _observers.remove(observer);
}