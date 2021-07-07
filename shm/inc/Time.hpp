#pragma once

#include <vector>

class Subscriber;

class Time {
public:
    void addSubscriber(Subscriber* subscriber);
    void removeSubscriber(Subscriber* subscriber);
    Time& operator++();
    size_t getElapsedTime() const;

private:
    size_t elapsedTime_{ 0 };
    std::vector<Subscriber*> subscribers_;

    void notifySubscribers();
};
