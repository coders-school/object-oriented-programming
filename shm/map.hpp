#pragma once

#include <vector>

#include "island.hpp"

constexpr int initialAmountOfIsland = 10;
constexpr int maxX = 10;
constexpr int maxY = 10;

class Map {
private:
    std::vector<Island> vecOfIslandOnMap_;
    Island* currentPosition_;

public:
    Map();
};