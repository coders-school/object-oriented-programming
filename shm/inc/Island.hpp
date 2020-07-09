#pragma once

#include "Coordinates.hpp"

class Island {
public:
    Coordinates getPosition() const;

    Island(size_t x, size_t y);

private:
    Coordinates position_;
};
