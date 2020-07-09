#include "../inc/Island.hpp"

#include "../inc/Coordinates.hpp"

Coordinates Island::getPosition() const { return position_; }

Island::Island(size_t x, size_t y)
    : position_(Coordinates(x, y)) { }
