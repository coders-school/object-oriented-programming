#include "island.hpp"
#include "coordinates.hpp"

Island::Island(Coordinates position) : position_(position) {}

Coordinates Island::getPosition() const {
    return position_;
}

Store Island::getStore() const {
    return store_;
}

void Island::createStore() {
    store_.generateCargo();
}
