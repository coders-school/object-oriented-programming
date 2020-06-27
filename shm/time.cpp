#include "time.hpp"

#include <algorithm>

constexpr size_t initialTime = 100; //days

Time::Time()
    : timeElapsed_(initialTime) {}

void Time::addObserver(Observer* obs) {
    observers_.push_back(obs);
}

void Time::removeObserver(Observer* obs) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
}

size_t Time::getElapsedTime() const {
    return timeElapsed_;
}

Time& Time::operator ++() {
    return *this;
}