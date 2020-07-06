#pragma once

#include <memory>
#include <vector>
#include "Observer.hpp"

class Time {
private:
    std::vector<Observer*> observers_{};
    size_t elapsedTime_{0};

    void notifyObservers() const;
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    size_t getElapsedTime() const;
    Time& operator++();
};
