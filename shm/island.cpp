#include "island.hpp"

Coordinates::Coordinates(size_t posX, size_t posY)
    : positionX(posX), positionY(posY)
{}

Island::Island(std::size_t posX, std::size_t posY)
    : position_(posX, posY)
{}

Coordinates Island::getPosition() {
    return position_;
}
