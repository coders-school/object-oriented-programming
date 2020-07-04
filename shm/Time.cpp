#include "Time.hpp"
#include <algorithm>

void Time::addObserver(std::shared_ptr<Observer> &observer) {
    observers_.push_back(observer);
}

void Time::removeObserver(std::shared_ptr<Observer> &observer) {



}
