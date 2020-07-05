#pragma once

#include <ostream>

#include "coordinates.hpp"

class Island : public Coordinates {
public:
    Island() {}
    Island(int posX, int posY);
    Coordinates getCoordinates() const { return position_; }

private:
    Coordinates position_;
};
