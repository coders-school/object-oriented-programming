#pragma once

class Observer {
public:
    virtual void nextDay() = 0;
    virtual ~Observer(){};
};
