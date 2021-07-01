#include "coordinates.hpp"


bool Coordinates::operator==(const Coordinates& other) const {
    if (positionX_ == other.positionX_ and positionY_ == other.positionY_ ) {
        return true;
    }
    return false;
}
