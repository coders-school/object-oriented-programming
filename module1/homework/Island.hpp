#pragma once

#include "Coordinates.hpp"

class Island {
    Coordinates position_;

public:
    Island() = default;
    Island(size_t, size_t);
    Coordinates getPosition() const;
};