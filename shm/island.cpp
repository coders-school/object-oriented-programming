#include "island.hpp"

Coordinates::Coordinates(int posX, int posY)
    : positionX(posX), positionY(posY)
{}

Coordinates Island::getPosition() {
    return position_;
}
