#include "island.hpp"
#include "map.hpp"
#include <iostream>
#include <algorithm>
#include <random>

/*Map::Map() {
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> widthDistribution(0, maxWidth_);
    // std::uniform_int_distribution<> heightDistribution(0, maxHeight_);

    randomGenerator_(randomDevice_());
    islands_.reserve(10);
    for (int i = 0; i < islandsQuantity_; ++i) {
        Island tempIsland(widthDistribution_(randomGenerator_), heightDistribution(gen));
        islands_.push_back(tempIsland);
    }
}*/

Island* const Map::getIsland(const Coordinates& coordinate) {
    for (auto& island : islands_) {
        if (island.getPosition() == coordinate) {
            return &island;
        }
    }
    std::cout << "Island not exist";
    return nullptr;
}
