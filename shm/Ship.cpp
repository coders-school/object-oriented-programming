#include "Ship.hpp"

Ship& Ship::operator-=(size_t num) {
    if (num > crew_) {
        crew_ = 0;
        return *this;
    }
    crew_ -= num;
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    if (crew_ + num > maxCrew_) {
        crew_ = maxCrew_;
        return *this;
    }
    crew_ += num;
    return *this;
}