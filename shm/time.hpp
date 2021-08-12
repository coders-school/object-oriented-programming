#pragma once
#include <memory>
#include <list>
#include "iObserver.hpp"

class IObserver;

class Time {
public:
    Time();
    ~Time() = default;


    void attachObeserver(IObserver * );

    void detachObeserver(IObserver * );

    void onTimeChange();


private:
    std::list<IObserver*> observerList_; 

    void notifyAll();

};