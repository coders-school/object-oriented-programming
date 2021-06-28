#pragma once
#include "coordinates.hpp"

class Island {
public:
    Island(const Coordinates& position)
        : position_(position)
    {}
    Coordinates getPosition() const { return position_; }
private:
    Coordinates position_;
};
