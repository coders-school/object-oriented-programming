#pragma once

class Observer {
public:
    virtual ~Observer();
    virtual void nextDay() = 0;
};
