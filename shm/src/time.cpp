#include "time.hpp"

#include <algorithm>

constexpr size_t startTime = 1;

Time::Time() : elapsedTime_(startTime) {}

void Time::addObserver(Observer* observer) {
    observers_.push_back(observer);
}
void Time::removeObserver(Observer* observer) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer));
}
void Time::notifyObservers() {
    for (auto observer : observers_)
        observer->nextDay();
}

size_t Time::getElapsedTime() const {
    return elapsedTime_;
}

Time& Time::operator++() {
    elapsedTime_++;
    notifyObservers();
    return *this;
}
