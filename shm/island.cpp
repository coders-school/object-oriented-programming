#include "island.hpp"

Coordinates Island::getPosition() const {
    return position_;
}

void Island::setPosition(Coordinates position){
    position_ = position;
}
