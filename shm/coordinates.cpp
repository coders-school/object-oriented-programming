#include "coordinates.hpp"

Coordinates::Coordinates()
    : positionX_(DEFAULT_POSITION_X), positionY_(DEFAULT_POSITION_Y) {}
   
Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Coordinates::operator==(const Coordinates& currentPosition) const {
    return positionX_ == currentPosition.positionX_ && positionY_ == currentPosition.positionY_;
}
