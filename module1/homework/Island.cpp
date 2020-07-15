#include "Island.hpp"

Island::Island(uint16_t positionX, uint16_t positionY)
    : position_(Coordinates(positionX, positionY)) {}

Coordinates Island::getPosition() const {
    return position_;
}
