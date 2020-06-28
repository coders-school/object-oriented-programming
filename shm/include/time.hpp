#pragma once

#include <vector>

#include "observer.hpp"

class Time {
public:
    Time();
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
    size_t getElapsedTime() const;

    Time& operator++();

private:
    std::vector<Observer*> observers_;
    size_t elapsedTime_;
};
