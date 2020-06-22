#include "island.hpp"

Island::Island(int position_X, int position_Y)
    : position_(Coordinates(position_X, position_Y)) {
}

Island::Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}

bool Island::Coordinates::operator==(const Coordinates& rhs) const {
    return ((positionX_ == rhs.positionX_) &&
            (positionY_ == rhs.positionY_));
}
