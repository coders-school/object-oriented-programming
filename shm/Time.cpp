#include "Time.hpp"

#include <algorithm>

void Time::addObserver(Observer* observer) {
    observers_.push_back(observer);
}

void Time::removeObserver(Observer* observer) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer));
}

Time& Time::operator++() {
    elapsedTime_++;
    notifyObservers();
    return *this;
}

void Time::notifyObservers() const {
    std::for_each(observers_.begin(), observers_.end(), [](const auto& el) { el->nextDay(); });
}

size_t Time::getElapsedTime() const {
    return elapsedTime_;
}
