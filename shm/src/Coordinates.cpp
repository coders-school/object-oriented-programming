#include "Coordinates.hpp"

#include <cstddef>

Coordinates::Coordinates(size_t x, size_t y)
    : positionX_(x), positionY_(y) { }

bool Coordinates::operator==(const Coordinates& coordinates) {
    return positionX_ == coordinates.positionX_ &&
        positionY_ == coordinates.positionY_;
}
