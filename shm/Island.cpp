#include "Island.hpp"
#include <string>

Island::Island(Island::coordinateType positionX, Island::coordinateType positionY)
    : position_{positionX, positionY} {}

std::ostream& operator<<(std::ostream& out, const Island::Coordinates& coords){
    out << "x: " << coords.positionX_ << ", y: " << coords.positionY_ << '\n';
    return out;
}
