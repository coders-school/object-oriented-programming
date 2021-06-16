#include "map.hpp"

std::vector<Island> Map::getIslandVec() const {
    return islandVec_;
}

Island* Map::getCurrentPosition() const{
    return currentPosition_;
}