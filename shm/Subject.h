#pragma once

#include "Observer.h"

class Subject {
public:
    virtual ~Subject(){};
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify() = 0;
};
