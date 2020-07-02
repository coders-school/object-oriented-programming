#include "island.hpp"

Island::Coordinates::Coordinates(size_t positionX, size_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

Island::Island(size_t position_X, size_t position_Y)
    : position_(Coordinates(position_X, position_Y)) {}

bool Island::Coordinates::operator==(const Coordinates& rhs) const {
    return ((positionX_ == rhs.positionX_) &&
            (positionY_ == rhs.positionY_));
}
