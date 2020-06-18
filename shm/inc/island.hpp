#pragma once

#include "coordinates.hpp"

class Island {
public:
    Island(int positionX, int positionY)
        : position_(Coordinates(positionX, positionY)) {}

    Coordinates getPosition() const { return position_; }

private:
    Coordinates position_;
};
