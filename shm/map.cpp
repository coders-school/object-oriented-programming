#include <algorithm>
#include <iostream>
#include <random>
#include "island.hpp"
#include "map.hpp"

Map::Map() {
    islands_.reserve(10);
    for (int i = 0; i < islandsQuantity_;) {
        Coordinates tempCoordinates = getRandomCoordinates();
        if (!getIsland(tempCoordinates)) {
            Island tempIsland(tempCoordinates);
            islands_.push_back(tempIsland);
            ++i;
        }
    }
}

Island* const Map::getIsland(const Coordinates& coordinate) {
    for (auto& island : islands_) {
        if (island.getPosition() == coordinate) {
            return &island;
        }
    }
    std::cout << "Island not exist";
    return nullptr;
}

Coordinates Map::getRandomCoordinates() {
    std::random_device randomDevice;
    std::mt19937 randomGenerator(randomDevice());
    std::uniform_int_distribution<> widthDistribution(0, maxWidth_);
    std::uniform_int_distribution<> heightDistribution(0, maxHeight_);
    Coordinates randomCoordinates(widthDistribution(randomGenerator), heightDistribution(randomGenerator));
    return randomCoordinates;
}
