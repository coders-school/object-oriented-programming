#include "Coordinates.hpp"

bool Coordinates::operator==(const Coordinates& coordinatesToCheck) const {
    return _positionX == coordinatesToCheck._positionX &&
           _positionY == coordinatesToCheck._positionY;
}

bool Coordinates::operator!=(const Coordinates& coordinatesToCheck) const {
    return !(*this == coordinatesToCheck);
}