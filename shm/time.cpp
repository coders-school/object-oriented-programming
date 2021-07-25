#include "time.hpp"

Time::Time() : dayNr_(0) {}

Time::Time(size_t dayNr) : dayNr_(dayNr) {}

size_t Time::endCurrentDay(size_t dayNr) {
    return ++dayNr;
}