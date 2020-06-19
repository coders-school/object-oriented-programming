#include "coordinates.hpp"

Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& other) {
    return (positionX_ == other.positionX_ && positionY_ == other.positionY_);
}
