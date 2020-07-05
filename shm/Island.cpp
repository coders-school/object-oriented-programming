#include "Island.h"

Island::Island(size_t position_x, size_t position_y, Time* time) {
    position_ = Coordinates(position_x, position_y);
    store_ = new Store(time);
}

Store* Island::getStore() {
    return store_;
}

Coordinates Island::getCoordinates() const {
    return position_;
}
