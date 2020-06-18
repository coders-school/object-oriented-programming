#include "map.hpp"

#include <algorithm>

Island* Map::getIsland(const Coordinates& coordinate) {

    auto island = std::find_if(islands_.begin(), islands_.end(),
                           [&](const auto& island) {
                               return coordinate == island.getPosition();
                           });
    return island != std::end(islands_) ? &*island : nullptr;
}
