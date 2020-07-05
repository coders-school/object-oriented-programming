#pragma once

#include <ostream>

#include "Coordinates.hpp"

class Island
{
public:
    Island();
    Island(int x, int y);

    Coordinates getPosition() { return position_; }

private:
    Coordinates position_;
};

bool operator==(Island& lhs, Island& rhs);
