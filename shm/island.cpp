#include "island.hpp"

Island::Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}

Island::Island(int position_X, int position_Y)
    : position_(Coordinates(position_X, position_Y)) {}

bool Island::Coordinates::operator==(const Coordinates& rhs) const {
    return ((positionX_ == rhs.positionX_) &&
            (positionY_ == rhs.positionY_));
}
