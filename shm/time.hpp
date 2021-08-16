#pragma once
#include <memory>
#include <list>
#include "iObserver.hpp"

class IObserver;

class Time {
public:
    Time();
    ~Time() = default;


    void attachObserver(IObserver * );

    void detachObserver(IObserver * );

    void onTimeChange();


private:
    std::list<IObserver*> observerList_; 

    void notifyAll();

};