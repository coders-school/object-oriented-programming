#include "shm/inc/Map.hpp"

#include <algorithm>
#include <cstddef>
#include <memory>
#include <random>

constexpr size_t COORDINATE_MIN = 0;
constexpr size_t COORDINATE_MAX = 99;
constexpr size_t ISLANDS_COUNT = 10;

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

Island* Map::getIsland(const Island::Coordinates& coordinates) {
    auto island_it = std::find_if(vectorOfIslands_.begin(), vectorOfIslands_.end(),
                                 [&coordinates](auto& island) {
                                     return island.getCoordinates() == coordinates;
                                 });
    return island_it != vectorOfIslands_.end()
           ? std::addressof(*island_it)
           : nullptr;
}
