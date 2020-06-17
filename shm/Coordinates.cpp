#include "Coordinates.hpp"

#include <iostream>

Coordinates::Coordinates(size_t positionX, size_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& coor) const {
    return ((coor.positionX_ == positionX_) && (coor.positionY_ == positionY_));
}
