#pragma once

#include <ostream>

#include "Coordinates.hpp"

class Island
{
public:
    Island();
    Island(int x, int y);

    Coordinates getPosition(); 

private:
    Coordinates position_;
};

bool operator==(Island& lhs, Island& rhs);
std::ostream& operator<<(std::ostream& os, Island& island);
