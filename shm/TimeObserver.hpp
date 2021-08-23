#ifndef TIMEOBSERVER_HPP
#define TIMEOBSERVER_HPP

class TimeObserver {
public:
    virtual ~TimeObserver() = default;
    virtual void nextDay() = 0;
};

#endif
