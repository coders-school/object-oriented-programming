#include "coordinates.hpp"

Coordinates::Coordinates(int32_t positionX, int32_t positionY) : positionX_(positionX), positionY_(positionY){};

bool Coordinates::operator==(const Coordinates& position) {
    return positionX_ == position.positionX_ && positionY_ == position.positionY_;
}
