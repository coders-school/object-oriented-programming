#include "coordinates.hpp"

bool Coordinates::operator==(const Coordinates& other) const {
    return positionX_ == other.positionX_ && positionY_ == other.positionY_;
}
Coordinates::Coordinates()
    : positionX_(0), positionY_(0) {}
Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}
