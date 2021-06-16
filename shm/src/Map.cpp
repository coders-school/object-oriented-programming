#include "Map.hpp"

#include <algorithm>
#include <random>

constexpr int COORDINATE_MIN = 0;
constexpr int COORDINATE_MAX = 99;
constexpr int ISLANDS_COUNT = 10;

Map::Map() {
    std::random_device rd;
    std::mt19937 generator(rd);
    std::uniform_int_distribution<> distribution{
        COORDINATE_MIN, COORDINATE_MAX
    };

    while (vectorOfIslands_.size() != ISLANDS_COUNT) {
        auto generatedIslandCoords{
            Island::Coordinates(distribution(generator),
                                distribution(generator))
        };
        auto result = std::find_if(vectorOfIslands_.begin(),
                                   vectorOfIslands_.end(),
                                   [&](const Island& island) {
                                       return island.getCoordinates() ==
                                               generatedIslandCoords;
                                   });
        if (result == vectorOfIslands_.end()) {
            vectorOfIslands_.push_back(Island(generatedIslandCoords));
        }
    }
}
