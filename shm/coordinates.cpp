#include "coordinates.hpp"

Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& rhs) const {
    return ((positionX_ == rhs.positionX_) &&
            (positionY_ == rhs.positionY_));
}
