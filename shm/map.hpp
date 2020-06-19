#pragma once

#include <vector>

#include "island.hpp"

constexpr int initialAmountOfIsland = 10;
constexpr int maxX = 10;
constexpr int maxY = 10;

class Map {
public:
    Map();
    Island* getIsland(const Island::Coordinates& coordinate);
    
private:
    std::vector<Island> islandsOnMap_;
    Island* currentPosition_;
};
