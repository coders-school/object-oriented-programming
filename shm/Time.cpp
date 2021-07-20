#include <iostream>

#include "Time.hpp"
#include "TimeEffectable.hpp"

Time::Time()
{
    currentTime_ = 0;
}

void Time::attach(TimeEffectable* observer)
{   
    list_observer_.push_back(observer);
}

void Time::detach(TimeEffectable* observer)
{
    list_observer_.remove(observer);
}

void Time::notify()
{
    for(auto el : list_observer_)
    {
        el->nextDay();
    }
}

void Time::changeTime()
{
    currentTime_++;
    notify();
}

void Time::HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
  }