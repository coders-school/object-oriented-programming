#ifndef TIME_HPP
#define TIME_HPP
#include <memory>
#include <vector>
#include "TimeObserver.hpp"

//Class used to simulate passing game time
class Time {
private:
    size_t timeElapsed_;
    std::vector<TimeObserver*> timeObservers_;
    //ObserverIT GetObserverIt(observer * obs);
public:
    Time();
    size_t GetElapsedTime() const { return timeElapsed_; };
    void AddObserver(TimeObserver* obs);
    void RemoveObserver(TimeObserver* obs);
    Time& operator++();
};

#endif