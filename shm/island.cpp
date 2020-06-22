#include "island.hpp"

Island::Island(size_t posX, size_t posY)
    : position_(Coordinates(posX, posY))
{}

Coordinates Island::getPosition() const { return position_; }
