#include "map.hpp"

std::vector<Island> Map::getIslandVec() const {
    return islandVec_;
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}
Island* Map::getIsland(const Island::Coordinates& coordinate) {
    for (auto& el : islandVec_) {
        if (&el.getPosition() == &coordinate) {
            return &el;
        }
    }
    return nullptr;
}