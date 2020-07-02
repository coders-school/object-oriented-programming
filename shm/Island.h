#pragma once

#include "Coordinates.h"

class Island {
public:
    Island() {}
    Island(size_t position_x, size_t position_y);
    Coordinates getCoordinates() const;

private:
    Coordinates position_;
};
