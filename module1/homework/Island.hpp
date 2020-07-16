#pragma once

#include "Coordinates.hpp"

class Island {
    Coordinates position_;

public:
    Island() = default;
    Island(uint16_t, uint16_t);
    Coordinates getPosition() const;
};