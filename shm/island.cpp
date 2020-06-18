#include "island.hpp"
#include "coordinates.hpp"

Island::Island(int positionX, int positionY) : position_(Coordinates(positionX, positionY)) {}

Coordinates Island::getPosition() const {
    return position_;
}
