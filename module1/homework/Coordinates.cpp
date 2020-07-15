#include "Coordinates.hpp"

Coordinates::Coordinates(size_t positionX, size_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

size_t Coordinates::getPositionX() const {
    return positionX_;
}
size_t Coordinates::getPositionY() const {
    return positionY_;
}

bool Coordinates::operator==(const Coordinates& coordinates) const {
    return coordinates.getPositionX() == positionX_ && coordinates.getPositionY() == positionY_;
}