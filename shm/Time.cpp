#include "Time.hpp"
#include <algorithm>

void Time::addObserver(std::shared_ptr<Observer> &observer) {
    observers_.push_back(observer);
}

void Time::removeObserver(std::shared_ptr<Observer> &observer) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer));
}

Time &Time::operator++() {
    elapsedTime_++;
    return *this;
}

void Time::notifyObservers() {
    std::for_each(observers_.begin(), observers_.end(), [](const auto& el){el->nextDay();});
}

size_t Time::getElapsedTime() const {
    return elapsedTime_;
}

void Time::resetTime() {
    elapsedTime_ = 0;
}

void Time::sendNotification() {
    notifyObservers();
    resetTime();
}
