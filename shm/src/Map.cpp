#include "../inc/Map.hpp"

#include <algorithm>
#include <cstddef>
#include <random>

constexpr size_t COORDINATE_MIN = 0;
constexpr size_t COORDINATE_MAX = 99;
constexpr size_t ISLANDS_COUNT = 10;

Map::Map() {
    // std::random_device rd;
    // std::mt19937 generator(rd);
    // std::uniform_int_distribution<> distribution{
    //     COORDINATE_MIN, COORDINATE_MAX
    // };
    // vectorOfIslands_.reserve(ISLANDS_COUNT);
    // while (vectorOfIslands_.size() != ISLANDS_COUNT) {
    //     auto generatedIslandCoords{
    //         Island::Coordinates(distribution(generator),
    //                             distribution(generator))
    //     };
    //     auto result = std::find_if(vectorOfIslands_.cbegin(),
    //                                vectorOfIslands_.cend(),
    //                                [&](const Island& island) {
    //                                    return island.getCoordinates() ==
    //                                            generatedIslandCoords;
    //                                });
    //     if (result == vectorOfIslands_.end()) {
    //         vectorOfIslands_.push_back(Island(generatedIslandCoords));
    //     }
    // }
    // currentPosition_ = std::make_unique<Island>(vectorOfIslands_[0]);
}

std::shared_ptr<Island> Map::getIsland(Island::Coordinates& coordinate) {
    for (auto const& vec : vectorOfIslands_) {
        if (vec.getCoordinates() != coordinate) {

        }
    }
    // std::shared_ptr<Island> islandPtr = nullptr;
    // std::find_if(vectorOfIslands_.begin(), vectorOfIslands_.end(), [&](auto vec) { return vec == coordinate; });
    return nullptr;
}
// std::shared_ptr<Island> Map::getIsland(Island& coordinate) {
//     //std::shared_ptr<Island> islandPtr = nullptr;
//     //std::find_if(vectorOfIslands_.begin(), vectorOfIslands_.end(), [&](auto vec) { return vec == coordinate); });
//     // if (islandCoordinate != vectorOfIslands_.end()) {
//     //     islandPtr = std::make_shared<Island>(*islandCoordinate);
//     // }
//     // return islandPtr ;
//     return nullptr;
// }
