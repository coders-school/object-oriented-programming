#pragma once

#include "coordinates.hpp"

class Island {
    Coordinates getCoordinates() const { return position_; }
private:
    Coordinates position_;
};
