#pragma once

#include "coordinates.hpp"

class Island {
public:
    Island(size_t posX, size_t posY);

    Coordinates getPosition() const;

private:
    Coordinates position_;
};
