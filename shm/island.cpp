#include "island.hpp"
#include "coordinates.hpp"

Island::Island(Coordinates position) : position_(position) {}

Coordinates Island::getPosition() const {
    return position_;
}
