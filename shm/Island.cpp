#include "Island.hpp"

Island::Island(uint16_t positionX, uint16_t positionY)
    : position_(Coordinates(positionX, positionY)) {
    store_ = std::make_shared<Store>();
}

Coordinates Island::getPosition() const {
    return position_;
}

std::shared_ptr<Store> Island::getStore() const {
    return store_;
}