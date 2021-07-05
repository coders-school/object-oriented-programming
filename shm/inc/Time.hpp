#pragma once

#include <vector>

class Subscriber;

class Time {
public:
    void addSubscriber(Subscriber* subscriber);
    void removeSubscriber(Subscriber* subscriber);
    void notifySubscribers();
    Time& operator++();

private:
    size_t elapsedTime_{};
    std::vector<Subscriber*> subscribers_;
};
