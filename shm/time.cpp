#include <iostream>
#include <memory>
#include <list>
#include "iObserver.hpp"
#include "time.hpp"



void Time::attachObeserver(std::shared_ptr<IObserver> observer) {
    observerList_.push_back(observer);
}

void Time::detachObeserver(std::shared_ptr<IObserver> observer) {
    observerList_.remove(observer);
}

void Time::onTimeChange() {
    notifyAll();
}

void Time::notifyAll() { 
    for(auto it = observerList_.begin(); it != observerList_.end(); ++it) {
        (*it)->nextDay();
    }
}