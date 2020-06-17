#pragma once
#include "coordinates.hpp"

class Island {
public:
    Island(int, int);
    Coordinates getPosition() const { return position_; }

private:
    Coordinates position_;
};
