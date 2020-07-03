#include "island.hpp"
#include "coordinates.hpp"

Island::Island(Coordinates position, Time* time) : position_(position), time_(time), store_(time)  {
    this->createStore();
}

Coordinates Island::getPosition() const {
    return position_;
}

Store Island::getStore() const {
    return store_;
}

void Island::createStore() {
    store_.generateCargo();
}
