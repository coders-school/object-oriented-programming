#pragma once

#include "Coordinates.hpp"

class Island {
public:
    Island();
    Island(int positionX, int positionY);

    bool operator==(const Island& island);

    Coordinates getPosition() const;

private:
    Coordinates position_;
};
