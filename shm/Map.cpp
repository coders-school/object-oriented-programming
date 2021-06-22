#include "Map.hpp"

Map::Map(Island* currentPosition)
    : currentPostion_(currentPosition)
    {}
void Map::initializeMap (const Island& island) {
    islands_.push_back(island);
}
Island* Map::getPosition() {
    return currentPostion_;
}