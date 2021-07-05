#pragma once

class Subscriber {
public:
    virtual ~Subscriber() = default;
    virtual void nextDay() = 0;
};
