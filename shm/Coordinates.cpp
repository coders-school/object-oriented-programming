#include "Coordinates.hpp"

#include <cmath>

Coordinates::Coordinates(uint16_t positionX, uint16_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

uint16_t Coordinates::getPositionX() const {
    return positionX_;
}

uint16_t Coordinates::getPositionY() const {
    return positionY_;
}

uint16_t Coordinates::Distance(const Coordinates& lhs, const Coordinates& rhs) {
    uint16_t distanceX = std::max(lhs.positionX_, rhs.positionX_) - std::min(lhs.positionX_, rhs.positionX_);
    uint16_t distanceY = std::max(lhs.positionY_, rhs.positionY_) - std::min(lhs.positionY_, rhs.positionY_);

    return static_cast<uint16_t>(std::floor(std::hypot(distanceX, distanceY)));
}

bool Coordinates::operator==(const Coordinates& coordinates) const {
    return coordinates.getPositionX() == positionX_ && coordinates.getPositionY() == positionY_;
}

std::ostream& operator<<(std::ostream& out, const Coordinates& coordinates) {
    out << "Coordinates: [" << std::setw(2) << coordinates.positionX_ << ", " << std::setw(2) << coordinates.positionY_ << "]";

    return out;
}