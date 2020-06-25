#include "time.hpp"

#include <algorithm>

constexpr size_t startTime = 1;

Time::Time()
    : timeElapsed_(startTime) {
}

void Time::addObserver(Observer* obs) {
    observers_.push_back(obs);
}

void Time::removeObserver(Observer* obs) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
}

size_t Time::getElapsedTime() const {
    return timeElapsed_;
}

Time& Time::operator++() {
    timeElapsed_++;
    for (const auto& observer : observers_) {
        observer->nextDay();
    }
    return *this;
}
