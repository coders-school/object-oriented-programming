#include "Island.h"

Island::Island(size_t position_x, size_t position_y, Time* time) {
    Coordinates coord(position_x, position_y);
    position_ = coord;
    store_ = new Store(time);
}

Store* Island::getStore() {
    return store_;
}

Coordinates Island::getCoordinates() const {
    return position_;
}
