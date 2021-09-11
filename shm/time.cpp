#include "time.hpp"
#include <iostream>
#include <list>
#include <memory>
#include "iObserver.hpp"

void Time::attachObserver(IObserver *observer)
{
    observerList_.push_back(observer);
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
    std::cout << "Is it even working?" << std::endl;
   // std::cout << observerList_.size() << std::endl;
    if (observerList_.begin() == observerList_.end()) {
        std::cout << "Co jest?????" << std::endl;
    }
    for (auto it = observerList_.begin(); it != observerList_.end(); it++)
    {
        std::cout << "Is it even working? From the loop" << std::endl;
        (*it)->nextDay();
    }
}

size_t Time::getDays() const {
    return daysNum_;
}

std::list<IObserver*> Time::getList() const {
    return observerList_;
}