#pragma once

#include "island.hpp"

#include <memory>
#include <vector>

constexpr int initialAmountOfIsland = 10;
constexpr int maxX = 10;
constexpr int maxY = 10;

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& desiredCoordinate);
    
private:
    std::vector<Island> islandsOnMap_;
    Island* currentPosition_;
};
