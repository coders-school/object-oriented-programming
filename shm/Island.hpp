#pragma once
#include "Coordinates.hpp"

class Island {
public:
    Island(size_t positionX, size_t positionY);
    Coordinates getPosition() const { return position_; }

private:
    Coordinates position_;
};
