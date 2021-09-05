#include <iostream>

#include "Time.hpp"
#include "TimeEffectable.hpp"

Time::Time()
{
    currentTime_ = 0;
}

Time::~Time(){}

void Time::attach(TimeEffectable* observer)
{   
    list_observer_.push_back(observer);
}

void Time::detach(TimeEffectable* observer)
{
    list_observer_.remove(observer);
}

void Time::notify(size_t & elapsedDays)
{
    for(auto el : list_observer_)
    {
        el->nextDay(elapsedDays);
    }
}

void Time::changeTime(size_t elapsedDays)
{
    currentTime_ += elapsedDays;
    notify(elapsedDays);
}

void Time::HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
  }