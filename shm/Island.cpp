#include "Island.hpp"

Island::Island(coordinateType positionX, coordinateType positionY)
    : position_{positionX, positionY} {}

Island::Coordinates Island::getPosition() const {
    return position_;
}

Island::Coordinates::Coordinates(coordinateType positionX, coordinateType positionY)
    : positionX_{positionX}, positionY_{positionY} {}

bool Island::Coordinates::operator==(const Coordinates& other) const {
    if (positionX_ == other.positionX_ and positionY_ == other.positionY_) {
        return true;
    }
    return false;
}