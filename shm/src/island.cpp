#include "island.hpp"
#include <cmath>

Coordinates::Coordinates(size_t posX, size_t posY)
    : positionX_(posX), positionY_(posY)
{}

static size_t distance(const Coordinates& lhs, const Coordinates& rhs) {
    return (size_t)sqrt(pow(rhs.getPositionX()-lhs.getPositionX(), 2)
                        + pow(rhs.getPositionY()-lhs.getPositionY(), 2));
}

Island::Island(size_t posX, size_t posY)
    : position_(posX, posY)
{}

Coordinates Island::getPosition() {
    return position_;
}
