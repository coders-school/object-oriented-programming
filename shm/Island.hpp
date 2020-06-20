#pragma once

#include "Coordinates.hpp"

class Island {
public:
    Island(int posX, int posY);
    Coordinates getPosition() const { return _position; }

private:
    Coordinates _position;
};
