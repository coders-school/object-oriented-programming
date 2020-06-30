#pragma once

#include <cstddef>

class Observer {
public:
    virtual void NextDay() = 0;
    virtual ~Observer() = default;
};

class Delegate {
public:
    virtual void PayCrew(size_t money) = 0;
    virtual ~Delegate() = default;
};
