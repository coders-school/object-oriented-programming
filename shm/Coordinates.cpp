#include "Coordinates.hpp"

bool Coordinates::operator==(const Coordinates& cord) {
    return (positionX_ == cord.positionX_) && (positionY_ == cord.positionY_);
}
