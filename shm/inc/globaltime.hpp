#pragma once

#include "time.hpp"

class GlobalTime {
public:
    static Time* getGlobalTime() { return globalTime_; }

    static void provideGlobalTime(Time* time) {
        globalTime_ = time;
    }

private:
    static Time* globalTime_;
};
