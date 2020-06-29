#include "time.hpp"

Time::Time() {}

Time::Time(int game_days)
    : time_elapsed_(game_days) {
};

void Time::addObserver(Observer* obs) {
    observers_.push_back(obs);
}

void Time::removeObserver(Observer* obs) {
    observers_.remove(obs);
}

size_t Time::getElapsedTime() const {
    return time_elapsed_;
}

// Prefix increment operator (decrement elapsed time)
Time& Time::operator++() {
    time_elapsed_--;
    auto it = observers_.begin();
    while (it != observers_.end()) {
        (*it)->nextDay();
        ++it;
    }
    return *this;
}

// Postfix increment operator (decrement elapsed time)
Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}
