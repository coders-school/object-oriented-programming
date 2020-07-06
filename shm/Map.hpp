#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "Island.hpp"

constexpr size_t defaultXsize = 10;
constexpr size_t defaultYsize = 11;

class Map
{

public:
    Map() : mapXsize(defaultXsize), mapYsize(defaultYsize) { randomIslandGenerator(10); }
    Map(int islandsAmount) { randomIslandGenerator(islandsAmount); }
    Map(int sizeY, int sizeX, int islandsAmount) : mapXsize(sizeY), mapYsize(sizeX)
    {
        randomIslandGenerator(islandsAmount);
    }

    std::vector<Island> getIslands() { return islands; }
    Island getIsland(const Coordinates& corr);

private:

    void randomIslandGenerator(size_t amount);
    size_t mapXsize;
    size_t mapYsize;
    std::vector<Island> islands;
    Island* currentPosition_;
};
