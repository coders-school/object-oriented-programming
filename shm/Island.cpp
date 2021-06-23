#include "Island.hpp"
#include <string>

Island::Island(coordinateType positionX, coordinateType positionY)
    : position_{positionX, positionY} {}

Island::Coordinates Island::getPosition() const {
    return position_;
}

Island::Coordinates::Coordinates(coordinateType positionX, coordinateType positionY)
    : positionX_{positionX}, positionY_{positionY} {}

std::string Island::Coordinates::toString() {
    return "x: " + std::to_string(positionX_) + ", y: " + std::to_string(positionY_);
}

bool Island::Coordinates::operator==(const Coordinates& other) const {
    if (positionX_ == other.positionX_ and positionY_ == other.positionY_) {
        return true;
    }
    return false;
}
