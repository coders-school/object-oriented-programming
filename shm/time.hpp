#pragma once
#include <iostream>

class Time {
private:
    size_t dayNr_;

public:
    Time();
    Time(size_t dayNr);

    size_t getDayNr() const { return dayNr_; }

    size_t endCurrentDay(size_t dayNr);
};
