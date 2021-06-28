#include "Coordinates.hpp"

Coordinates::Coordinates(size_t positionX, size_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& coordinates) {
    return (positionX_ == coordinates.getPositionX()) && (positionY_ == coordinates.getPositionY());
}