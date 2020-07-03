#pragma once

#include "observerTime.hpp"

class SubjectTime {
public:
    virtual void registerObserver(ObserverTime* o) = 0;
    virtual void unregisterObserver(ObserverTime* o) = 0;
    virtual ~SubjectTime() = default;
};
