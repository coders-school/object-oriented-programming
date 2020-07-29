#pragma once

class Observer {
public:
    virtual ~Observer() = default;
    virtual void nextDay() = 0;
};
