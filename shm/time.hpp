#pragma once
#include <memory>
#include <list>
#include "iObserver.hpp"

class IObserver;

class Time {
public:
    Time();
    ~Time() = default;


    void attachObeserver(std::shared_ptr<IObserver> );

    void detachObeserver(std::shared_ptr<IObserver> );

    void onTimeChange();


private:
    std::list<std::shared_ptr<IObserver>> observerList_; 

    void notifyAll();

};