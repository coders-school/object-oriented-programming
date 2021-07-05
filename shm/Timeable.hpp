#pragma once

class Timeable {
public:
    Timeable();
    virtual ~Timeable();
    virtual void nextDay() = 0;
};
