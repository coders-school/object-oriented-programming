#include "Coordinates.hpp"

#include <math.h>

bool Coordinates::operator==(const Coordinates& cord) const {
    return (positionX_ == cord.positionX_) && (positionY_ == cord.positionY_);
}

bool Coordinates::operator!=(const Coordinates& cord) const {
    return (positionX_ != cord.positionX_) || (positionY_ != cord.positionY_);
}

//static
size_t Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    return static_cast<size_t>(std::floor(std::sqrt(
        std::pow(static_cast<int>(lhs.positionX_) - static_cast<int>(rhs.positionX_), 2) +
        std::pow(static_cast<int>(lhs.positionY_) - static_cast<int>(rhs.positionY_), 2))));
}
