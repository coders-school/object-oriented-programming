#include "Map.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <stdexcept>

constexpr int COORDINATE_MIN = 0;
constexpr int COORDINATE_MAX = 99;
constexpr int ISLANDS_COUNT = 10;
constexpr int TRIALS = ISLANDS_COUNT * 10;

Map::Map() {
    std::random_device rd;
    std::mt19937 generator(rd);
    std::uniform_int_distribution<> distribution{
        COORDINATE_MIN, COORDINATE_MAX
    };
    int count{};
    while (vectorOfIslands_.size() != ISLANDS_COUNT || count < TRIALS) {
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
        ++count;
    }
    try {
        currentPosition_ = &(vectorOfIslands_.at(0));
    } catch (const std::out_of_range& e) {
        std::cerr << "Object construction error: " << e.what() << std::endl;
    }
}
