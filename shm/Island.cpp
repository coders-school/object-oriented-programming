#include "Island.hpp"
#include "Coordinates.hpp"

auto Island::getPosition() const {
    return position_;
}

bool operator==(const Coordinates& lhs, const Coordinates& rhs) {
    if (lhs.posX == rhs.posX and lhs.posY == rhs.posY) {
        return true;
    }
    return false;
}