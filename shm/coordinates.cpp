#include "coordinates.hpp"

void Coordinates::setPositionX(size_t positionX) {
    positionX = positionX_;
}
size_t Coordinates::getPositionX() const {
    return positionX_;
}

void Coordinates::setPositionY(size_t positionY) {
    positionY = positionY_;
}
size_t Coordinates::getPositionY() const {
    return positionY_;
}

bool Coordinates::operator== (const Coordinates n_pos) const {
    return positionX_ == n_pos.positionX_ && positionY_ == n_pos.positionY_;
}

size_t Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    return std::round(std::sqrt(std::pow((static_cast<int>(lhs.getPositionX()) - static_cast<int>(rhs.getPositionX())),2) + std::pow((static_cast<int>(lhs.getPositionY()) - static_cast<int>(rhs.getPositionY())),2)));
}
