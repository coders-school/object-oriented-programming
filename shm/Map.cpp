#include "Map.hpp"

#include <algorithm>

void Map::setCurrentPosition(Island* const currentPosition) {
    currentPosition_ = currentPosition;
}

void Map::addIsland(const Island& newIsland) {
    islandsLocations_.push_back(newIsland);
}

Island* Map::getIsland(const Coordinates& coordinate)
{
    auto island = std::find_if(islandsLocations_.begin(), islandsLocations_.end(),
    [&coordinate](auto& isld)
    {
        return isld.Island::getPosition() == coordinate;
    });

    return &(*island);
}

