#include "Island.hpp"
#include <string>

Island::Island(Island::coordinateType positionX, Island::coordinateType positionY)
    : position_{positionX, positionY} {}

Island::Island(Island::Coordinates position)
    : position_{position} {}

std::ostream& operator<<(std::ostream& out, const Island::Coordinates& coords){
    out << "x: " << coords.positionX_ << ", y: " << coords.positionY_ << '\n';//new line to remove
    return out;
}
