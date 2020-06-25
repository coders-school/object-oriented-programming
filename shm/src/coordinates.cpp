#include "coordinates.hpp"

Coordinates::Coordinates(size_t positionX, size_t positionY)
    : positionX_(positionX), positionY_(positionY)
{}

bool Coordinates::operator==(const Coordinates& position) const {
    return (positionX_ == position.positionX_) &&
           (positionY_ == position.positionY_);
}

size_t Coordinates::getPositionX() const { return positionX_; }
size_t Coordinates::getPositionY() const { return positionY_; }
