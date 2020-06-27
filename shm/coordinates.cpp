#include "coordinates.hpp"

Coordinates::Coordinates() : positionX_(0), positionY_(0) {}

Coordinates::Coordinates(int32_t positionX, int32_t positionY) : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& position) {
    return positionX_ == position.positionX_ && positionY_ == position.positionY_;
}

int32_t Coordinates::getPositionX() const {
    return positionX_;
}

int32_t Coordinates::getPositionY() const {
    return positionY_;
}
