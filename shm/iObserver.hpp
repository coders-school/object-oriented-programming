#pragma once

class IObserver {
public:
    virtual void nextDay() = 0;
    virtual ~IObserver() = default;
};