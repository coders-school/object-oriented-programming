#pragma once

#include "Coordinates.hpp"

class Island {
public:
    Coordinates getPosition() const { return _position; }

private:
    Coordinates _position;
};