 #include "time.hpp"
#include <iostream>
#include <list>
#include <memory>
#include "iObserver.hpp"

void Time::attachObserver(IObserver *observer)
{
    observerList_.push_back(observer);
    std::cout << observerList_.size() << std::endl;
}

void Time::detachObserver(IObserver *observer)
{
    observerList_.remove(observer);
}

void Time::onTimeChange()
{
    notifyAll();
    daysNum_++;
}

void Time::notifyAll()
{   
    for (auto it = observerList_.begin(); it != observerList_.end(); it++)
    {
        if (*it) {
            (*it)->nextDay();
        }
    }
}

size_t Time::getDays() const {
    return daysNum_;
}

std::list<IObserver*> Time::getList() const {
    return observerList_;
}