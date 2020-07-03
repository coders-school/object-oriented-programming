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

std::ostream& operator<<(std::ostream& out, const Coordinates& coord) {
    out << "[ x: " << coord._positionX;
    out << " | y: " << coord._positionY << " ]";
    return out;
}
