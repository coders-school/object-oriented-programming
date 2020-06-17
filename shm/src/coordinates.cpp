#include "coordinates.hpp"

bool Coordinates::operator==(const Coordinates& coordToCheck) const {

    return positionX_ == coordToCheck.positionX_ &&
           positionY_ == coordToCheck.positionY_;
}
