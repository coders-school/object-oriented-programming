#pragma once

class Timeable {
public:
    virtual ~Timeable() {};
    virtual void nextDay() = 0;
};