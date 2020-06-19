#include "coordinates.hpp"

Coordinates::Coordinates()
    : positionX_(0), positionY_(0) {}
    
Coordinates::Coordinates(const int positionX, const int positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& currentPosition) {
    return positionX_ == currentPosition.positionX && positionY_ == currentPosition.positionY;
}
