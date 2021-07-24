#include "Coordinates.hpp"
#include <cmath>

bool Coordinates::operator==(const Coordinates& coordinates) {
    return (positionX_ == coordinates.getPositionX()) && (positionY_ == coordinates.getPositionY());
}

size_t Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    return std::sqrt(std::pow((int)lhs.getPositionX() - (int)rhs.getPositionX(), 2) + std::pow((int)lhs.getPositionY() - (int)rhs.getPositionY(), 2));
}