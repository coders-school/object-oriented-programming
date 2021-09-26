#include "island.hpp"
#include <memory>

Island::Island(Coordinates position, std::shared_ptr<Store> store)
    : position_(position), store_(store)
    {}

Coordinates Island::getPosition() const {
    return position_;
}

void Island::setPosition(Coordinates position) {
    position_ = position;
}

std::shared_ptr<Store> Island::getStore() {
    return store_;
}
