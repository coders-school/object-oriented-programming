#pragma once
#include "coordinates.hpp"

class Island
{
private:
    Coordinates position_;

public:
    Island(Coordinates position)
    {
        position_ = position;
    }
    Coordinates getPosition() { return position_; }
    void SetPosition(const Coordinates &position) { position_ = position; }
};
