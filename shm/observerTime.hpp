#pragma once

class ObserverTime {
public:
    virtual void nextDay() = 0;
    virtual ~ObserverTime() = default;
};
