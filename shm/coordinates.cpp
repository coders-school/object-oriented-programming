#include "coordinates.hpp"

Coordinates::Coordinates(const int positionX, const int positionY)
    : positionX_(positionX), positionY_(positionY){};

bool Coordinates::operator==(Coordinates& position) {
    return positionX_ == position.positionX_ && positionY_ == position.positionY_;
}
