#ifndef TIME_HPP
#define TIME_HPP
#include <vector>
#include <memory>
#include "TimeObserver.hpp"

//Class 
class Time {

private: 

size_t timeElapsed_;
std::vector<std::shared_ptr<TimeObserver>> timeObservers_;
//ObserverIT GetObserverIt(observer * obs);
public:

Time();
size_t GetElapsedTime() const {return timeElapsed_;};
void AddObserver(std::shared_ptr<TimeObserver> obs);
void RemoveObserver(std::shared_ptr<TimeObserver> obs);
Time& operator++();


};

#endif