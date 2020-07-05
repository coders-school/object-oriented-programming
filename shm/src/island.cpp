#include "island.hpp"

#include <cmath>

#include "game.hpp"

Coordinates::Coordinates(size_t posX, size_t posY)
    : positionX_(posX), positionY_(posY) {}

static size_t distance(const Coordinates& lhs, const Coordinates& rhs) {
    return (size_t)sqrt(pow(rhs.getPositionX() - lhs.getPositionX(), 2) + pow(rhs.getPositionY() - lhs.getPositionY(), 2));
}

Island::Island(size_t posX, size_t posY, std::shared_ptr<Time> time)
    : position_(posX, posY), store_(Store(time)) {
}

Coordinates Island::getPosition() {
    return position_;
}
