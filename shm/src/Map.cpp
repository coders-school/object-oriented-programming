#include "Map.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
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
    vectorOfIslands_.reserve(ISLANDS_COUNT);
    while (vectorOfIslands_.size() != ISLANDS_COUNT || count < TRIALS) {
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
        ++count;
    }
    try {
        currentPosition_ = std::make_unique<Island>(vectorOfIslands_.at(0));
    } catch (const std::out_of_range& e) {
        std::cerr << "None of the islands created: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Object construction error: " << e.what() << std::endl;
    }
}
