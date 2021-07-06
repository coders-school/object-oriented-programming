#pragma once
#include "coordinates.hpp"

class Island {    
public:
    Island(Coordinates position)
    : position_(position)
    {}

    Coordinates getPosition() const;

private:
    Coordinates position_;
};