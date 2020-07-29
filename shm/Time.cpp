#include <algorithm>
#include "Time.hpp"

Time& Time::operator++()
{
    ++time_elapsed_;
    notify();
    return *this;
}


void Time::addObserver(Observer* obs)
{
    observers_.push_back(obs);
}
void Time::removeObserver(Observer* obs)
{
    observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
}

void Time::notify()
{
    for (const auto& obs : observers_)
    {
        obs->NextDay();
    }
}