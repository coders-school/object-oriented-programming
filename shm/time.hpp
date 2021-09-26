#pragma once
#include <memory>
#include <list>
#include "iObserver.hpp"

class IObserver;

class Time {
public:
    Time() = default;
    ~Time() = default;

    void attachObserver(IObserver * );

    void detachObserver(IObserver * );

    void onTimeChange();

    size_t getDays() const;

    std::list<IObserver*> getList() const;
private:
    std::list<IObserver*> observerList_{};
    void notifyAll();
    size_t daysNum_ = 0;

};
