#pragma once

#include <stdint.h>

#include <vector>

#include "Observer.hpp"

class Time {
    uint16_t timeElapsed_{};
    std::vector<Observer*> observers_;

public:
    Time() = default;

    void addObserver(Observer*);
    void removeObserver(Observer*);
    void notify();

    uint16_t getElapsedTime() const;
    Time& operator++();
};