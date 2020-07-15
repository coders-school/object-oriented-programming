#include "Island.hpp"

Island::Island(size_t positionX, size_t positionY)
    : position_(Coordinates(positionX, positionY)) {}

Coordinates Island::getPosition() const {
    return position_;
}
