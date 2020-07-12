#pragma once

#include "Coordinates.hpp"

class Island {
private:
    Coordinates position_;

public:
    Island(size_t positionX, size_t positionY);
    Coordinates getPosition() const { return position_; };
};
