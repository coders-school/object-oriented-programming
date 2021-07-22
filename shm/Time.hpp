#pragma once

#include <list>

class TimeEffectable;

class Time {
public:
    Time();
    ~Time();

    void attach(TimeEffectable* observer);
    void detach(TimeEffectable* observer);
    void notify();
    void changeTime();
    void HowManyObserver();
    size_t getCurrentTime() { return currentTime_; }
    
private:
    std::list<TimeEffectable*> list_observer_;
    size_t currentTime_;
};