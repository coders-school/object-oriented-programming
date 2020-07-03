#include "time.hpp"

#include <algorithm>
#include <iostream>

void Time::addObserver(Observer *obs) {
    observers_.push_back(obs);
}
void Time::removeObserver(Observer *obs) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
}
Time& Time::operator++() {
    ++time_elapsed_;
    notify();
    return *this;
}

void Time::notify() {
    std::cout << "<><><><>ObserversCount: " << observers_.size() << "\n";
    for (const auto& obs : observers_) {
        obs->nextDay();
    }
}
