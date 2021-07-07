#include "shm/inc/Map.hpp"

#include <algorithm>
#include <cstddef>
#include <random>

Map::Map() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<size_t> distribution{
        COORDINATE_MIN, COORDINATE_MAX
    };
    vectorOfIslands_.reserve(ISLANDS_COUNT);
    while (vectorOfIslands_.size() != ISLANDS_COUNT) {
        auto generatedIslandCoords{
            Island::Coordinates(distribution(generator),
                                distribution(generator))
        };
        auto result = std::find_if(vectorOfIslands_.cbegin(),
                                   vectorOfIslands_.cend(),
                                   [&](const Island& island) {
                                       return island.getCoordinates() ==
                                               generatedIslandCoords;
                                   });
        if (result == vectorOfIslands_.end()) {
            vectorOfIslands_.push_back(Island(generatedIslandCoords));
        }
    }
    currentPosition_ = &(vectorOfIslands_[0]);
}

Island* Map::getIsland(const Island::Coordinates& coordinate) {
    for (auto & island : vectorOfIslands_) {
        if (island.getCoordinates() == coordinate) {
            return &island;
        }
    }

    return nullptr;
}
