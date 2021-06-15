#pragma once

#include "Coordinates.hpp"

class Island {
public:
    Island(size_t posX, size_t posY)
        : position_{posX, posY} {}

    auto getPosition() const;

    class Coordinates;

private:
    Coordinates position_;
};

bool operator==(const Coordinates& lhs, const Coordinates& rhs);