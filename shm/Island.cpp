#include "Island.hpp"
#include <string>

Island::Island(Island::coordinateType positionX, Island::coordinateType positionY)
    : position_{positionX, positionY} {}

constexpr Island::Coordinates::Coordinates(Island::coordinateType positionX, Island::coordinateType positionY)
    : positionX_{positionX}, positionY_{positionY} {}

bool Island::Coordinates::operator==(const Coordinates& other) const {
    return positionX_ == other.positionX_ and positionY_ == other.positionY_;
}

std::ostream& operator<<(std::ostream& out, const Island::Coordinates& coords){
    out << "x: " << coords.positionX_ << ", y: " << coords.positionY_ << '\n';
    return out;
}