#include "coordinates.hpp"

void Coordinates::setPositionX(size_t positionX) {
    positionX_ = positionX;
}
size_t Coordinates::getPositionX() const {
    return positionX_;
}

void Coordinates::setPositionY(size_t positionY) {
    positionY_ = positionY;
}
size_t Coordinates::getPositionY() const {
    return positionY_;
}

bool Coordinates::operator== (const Coordinates& n_pos) const {
    return positionX_ == n_pos.getPositionX() && positionY_ == n_pos.getPositionY();
}

size_t Coordinates::distance(const Coordinates& rhs) {
    return std::round(std::sqrt(std::pow((static_cast<int>(positionX_) - static_cast<int>(rhs.getPositionX())),2) + std::pow((static_cast<int>(positionY_) - static_cast<int>(rhs.getPositionY())),2)));
}
