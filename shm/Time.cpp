#include "Time.hpp"
#include <algorithm>

/* Time* Time::getInstance() {
    if (!instance_) {
        instance_ = std::unique_ptr<Time>(new Time);
    }
    return instance_.get();
} */

Time::Time() : timeElapsed_(0) {}

void Time::AddObserver(std::shared_ptr<TimeObserver> obs){
    if(obs){
        timeObservers_.push_back(obs);
    }
}
void Time::RemoveObserver(std::shared_ptr<TimeObserver> obs){
    timeObservers_.erase(std::find(std::begin(timeObservers_), std::end(timeObservers_), obs));
}

Time &Time::operator++()
{
    timeElapsed_++;
    for(const auto &timeObserver : timeObservers_){
        timeObserver->nextDay();
    }
    return *this;
}