#include "island.hpp"
#include <memory>

Coordinates Island::getPosition() const {
    return position_;
}

void Island::setPosition(Coordinates position){
    position_ = position;
}

std::shared_ptr<Store> Island::getStore() {
    return std::make_shared<Store>(store_);
}