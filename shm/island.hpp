#pragma once
#include "coordinates.hpp"

//island will be descibed as x, y possition from coordiates class
class Island {
public:
    explicit Island(const Coordinates&);
    Coordinates getPosition() const { return position_; }

private:
    Coordinates position_;
};
