#include "map.hpp"

#include <algorithm>

Island* Map::getIsland(const Coordinates& coordinate) {
    auto result = std::find_if(Islands_.begin(), Islands_.end(), [coordinate](const Island& islnd) {
        return islnd.getCoordinates() == coordinate;
    });
    return &(*result);
}