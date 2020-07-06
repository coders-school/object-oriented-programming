#include "island.hpp"
#include "coordinates.hpp"

Island::Island(Coordinates position, Time* time) : position_(position), time_(time) {
    store_ = std::shared_ptr<Store>(new Store(time));
}

Coordinates Island::getPosition() const {
    return position_;
}

std::shared_ptr<Store> Island::getStore() const {
    return store_;
}

void Island::createStore() {
    store_->generateCargo();
}
