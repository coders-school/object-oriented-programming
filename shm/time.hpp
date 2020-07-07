#pragma once

#include <cstdint>
#include <vector>

class ObserverTime {
public:
    virtual void nextDay() = 0;
    virtual ~ObserverTime() = default;
};

class Time {
public:
    Time() = default;

    void registerObserver(ObserverTime* o);
    void unregisterObserver(ObserverTime* o);

    uint32_t getElapsedTime() const;
    Time& operator++();

private:
    uint32_t elapsedTime_;
    std::vector<ObserverTime*> observersList_;
};
