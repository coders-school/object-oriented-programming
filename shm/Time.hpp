#pragma once

#include "Observer.hpp"
#include <vector>
#include <memory>

class Time {
private:
    std::vector<Observer*> observers_ {};
    size_t elapsedTime_ {0};

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void resetTime();
    void notifyObservers();
    size_t getElapsedTime() const;
    Time& operator++();
};
