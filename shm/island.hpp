#pragma once

#include "coordinates.hpp"

class Island {
public:
    Coordinates getIslandPosition() { return position_; };

private:
    Coordinates position_;
};