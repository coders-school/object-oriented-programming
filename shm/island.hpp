#pragma once

#include "coordinates.hpp"

class Island {
public:
    Coordinates getCoordinates() const { return position_; };

private:
    Coordinates position_;
};
