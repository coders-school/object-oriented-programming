#include "shm/inc/Map.hpp"

#include <algorithm>
#include <cstddef>
#include <memory>
#include <random>

Map::Map() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<size_t> distribution{
        COORDINATE_MIN, COORDINATE_MAX
    };
    islands_.reserve(ISLANDS_COUNT);
    while (islands_.size() != ISLANDS_COUNT) {
        auto generatedIslandCoords{
            Island::Coordinates(distribution(generator),
                                distribution(generator))
        };
        auto result = std::find_if(islands_.cbegin(),
                                   islands_.cend(),
                                   [&](const Island& island) {
                                       return island.getCoordinates() ==
                                               generatedIslandCoords;
                                   });
        if (result == islands_.end()) {
            islands_.push_back(Island(generatedIslandCoords));
        }
    }
    currentPosition_ = &(islands_[0]);
}

Island* Map::getIsland(const Island::Coordinates& coordinates) {
    auto island_it = std::find_if(islands_.begin(), islands_.end(),
                                 [&coordinates](auto& island) {
                                     return island.getCoordinates() == coordinates;
                                 });
    return island_it != islands_.end()
           ? std::addressof(*island_it)
           : nullptr;
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}

void Map::setCurrentPosition(Island* island) {
    currentPosition_ = island;
}
