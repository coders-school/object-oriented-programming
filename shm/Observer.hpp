#pragma once

#include <cstddef>

class Observer {
public:
    virtual void nextDay() = 0;
    virtual ~Observer() = default;
};

class Delegate {
public:
    virtual void payCrew(size_t money) = 0;
    virtual ~Delegate() = default;
};
