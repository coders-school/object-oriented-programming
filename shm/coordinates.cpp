#include "coordinates.hpp"

bool Coordinates::operator==(Coordinates& position) {
    return positionX_ == position.positionX_ && positionY_ == position.positionY_;
}
