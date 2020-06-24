#pragma once

#include "coordinates.hpp"

class Island {
public:
    Island() {}
    Island(int posX, int posY);
    Coordinates getCoordinates() const { return position_; }

private:
    Coordinates position_;
};
