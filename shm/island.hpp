#pragma once
#include "coordinates.hpp"

class Island {
public:
    Island(int position_X, int position_Y);
    Coordinates getPosition() const { return position_; }

// private:
    Coordinates position_;
};
