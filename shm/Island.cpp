#include "Island.hpp"
#include <string>

Island::Island(Island::CoordinateType coordinateX, Island::CoordinateType coordinateY)
    : position_{coordinateX, coordinateY} {}

Island::Island(Island::Position position)
    : position_{position} {}

std::ostream& operator<<(std::ostream& out, const Island::Position& position) {
    out << "x: " << position.coordinateX_ << ", y: " << position.coordinateY_ << '\n';  //new line to remove
    return out;
}
