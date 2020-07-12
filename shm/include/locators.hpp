#pragma once

#include "time.hpp"

class TimeServiceLocator {
public:
    static Time* getTime();
    static void provide(Time* time);

private:
    static Time* time_;
};
