#include "coordinates.hpp"

#include <cmath>

Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& other) {
    return (positionX_ == other.positionX_ && positionY_ == other.positionY_);
}

size_t Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    int x_distance = lhs.positionX_ - rhs.positionX_;
    int y_distance = lhs.positionY_ - rhs.positionY_;
    return std::sqrt(x_distance * x_distance + y_distance * y_distance);
}
