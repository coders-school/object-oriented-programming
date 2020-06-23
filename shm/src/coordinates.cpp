#include "coordinates.hpp"

#include <cmath>

bool Coordinates::operator==(const Coordinates& coordToCheck) const {
    return positionX_ == coordToCheck.positionX_ &&
           positionY_ == coordToCheck.positionY_;
}

size_t Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    return static_cast<size_t>(
        std::floor(std::sqrt(
            std::pow(lhs.positionX_ - rhs.positionX_, 2) +
            std::pow(lhs.positionY_ - rhs.positionY_, 2))));
}
