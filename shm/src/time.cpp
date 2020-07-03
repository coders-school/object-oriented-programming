#include "time.hpp"

#include <algorithm>

void Time::AddObserver(Observer *obs) {
    observers_.push_back(obs);
}
void Time::RemoveObserver(Observer *obs) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
}
Time& Time::operator++() {
    time_elapsed_++;
    notify();
    return *this;
}

void Time::notify() {
    for (const auto obs : observers_) {
        obs->nextDay();
    }
}
