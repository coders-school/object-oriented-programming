#pragma once
#include "coordinates.hpp"

#include <cstddef>

class Island {
public:
    Island(size_t, size_t);
    Coordinates getPosition() const { return position_; }

private:
    Coordinates position_;
};
