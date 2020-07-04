#include "timeSHM.hpp"

#include <algorithm>

constexpr size_t initialTime = 1; //days

Time::Time()
    : timeElapsed_(initialTime) {}

bool Time::findObserver(Observer* obs) {
    auto itr = std::find_if(observers_.begin(), observers_.end(),
                            [obs](const auto * temp) {
                                return temp == obs;
                            });
    return itr != observers_.end();
}
void Time::addObserver(Observer* obs) {
    if(!findObserver(obs)){
        observers_.push_back(obs);
    }
}
void Time::removeObserver(Observer* obs) {
    if(findObserver(obs)) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
    }
}

size_t Time::getElapsedTime() const {
    return timeElapsed_;
}

void Time::notifyObservers() {
for(auto& observer: observers_){
    if(observer != *observers_.end()){
    observer->nextDay();
}}}

Time& Time::operator++() {
    timeElapsed_++;
    for (const auto & obs : observers_)
        obs->nextDay();
    return *this;
}
