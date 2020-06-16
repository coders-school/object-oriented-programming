#include "coordinates.hpp"

Coordinates::Coordinates(size_t positionX, size_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& rhs) const {
    return ((positionX_ == rhs.positionX_) &&
            (positionY_ == rhs.positionY_));
}
