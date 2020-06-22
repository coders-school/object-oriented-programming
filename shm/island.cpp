#include "island.hpp"

Island::Island(size_t posX, size_t posY)
    : position_(posX, posY)
{}

Coordinates Island::getPosition() const { return position_; }
