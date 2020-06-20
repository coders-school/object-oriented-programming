#include "Coordinates.hpp"

Coordinates::Coordinates(const int positionX,
                         const int positionY)
    : _positionX(positionX), _positionY(positionY) {}

bool Coordinates::operator==(const Coordinates& coordinatesToCheck) const {
    return _positionX == coordinatesToCheck._positionX &&
           _positionY == coordinatesToCheck._positionY;
}

bool Coordinates::operator!=(const Coordinates& coordinatesToCheck) const {
    return !(*this == coordinatesToCheck);
}
