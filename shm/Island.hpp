#pragma once

#include "Coordinates.hpp"

class Island {
private:
    Coordinates position_;
public:
    Island(size_t positionX, size_t positionY) : position_(positionX, positionY) {};
    const Coordinates& getPosition() { return position_; };
};