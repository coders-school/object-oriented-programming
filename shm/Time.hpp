#pragma once

#include "Observer.hpp"
#include <vector>
#include <memory>

class Time {
private:
    std::vector<std::shared_ptr<Observer>> observers_ {};
    size_t elapsedTime_ {0};

    void resetTime();
    void notifyObservers();
public:
    void addObserver(std::shared_ptr<Observer> &observer);
    void removeObserver(std::shared_ptr<Observer> &observer);
    void sendNotification();
    size_t getElapsedTime() const;
    Time& operator++();
};
