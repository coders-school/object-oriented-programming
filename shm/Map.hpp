#pragma once

#include <vector>

#include "Island.hpp"

constexpr int minPositionXY = 1;
constexpr int maxPositionXY = 10;

class Map {
public:
    Map(size_t numberOfIslands);
    Island* getIsland(const Coordinates& coordinate);

private:
    std::vector<Island> _vecOfIslands;
    Island* _currentPosition;
};
