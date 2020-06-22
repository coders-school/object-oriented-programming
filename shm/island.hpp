#pragma once

#include "coordinates.hpp"

#include <string>

class Island {
public:
    Island(size_t posX, size_t posY);

    void setPosition(size_t posX, size_t posY);
    Coordinates getPosition() const;

private:
    Coordinates position_;
};
