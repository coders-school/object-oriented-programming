#include "time.hpp"

#include <algorithm>

// override from ObserverTime

void Time::registerObserver(ObserverTime* o) {
    observersList_.emplace_back(o);
}

void Time::unregisterObserver(ObserverTime* o) {
    auto it = std::find(observersList_.begin(), observersList_.end(), o);
    if (it != observersList_.end()) {
        observersList_.erase(it);
    }
}

uint32_t Time::getElapsedTime() const {
    return elapsedTime_;
}

Time& Time::operator++() {
    if (!observersList_.empty()) {
        for (const auto& singleObserver : observersList_) {
            singleObserver->nextDay();
        }
    }
    return *this;
}
