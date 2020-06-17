#pragma once

#include "coordinates.hpp"

class Island {
public:
    Coordinates getPosition() const { return position_; }


private:
    Coordinates position_;
};
