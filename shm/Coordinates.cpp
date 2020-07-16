#include "Coordinates.hpp"

Coordinates::Coordinates()
    : positionX_(0)
    , positionY_(0)
{}
Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX)
    , positionY_(positionY)
{}

bool Coordinates::operator==(const Coordinates& coords) {
    return ((positionX_ == coords.positionX_) && (positionY_ == coords.positionY_));
}

