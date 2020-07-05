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
    Island getIsland(const Coordinates& corr)
    {
        return *(std::find_if(
            std::begin(islands), std::end(islands), [corr](Island& is) { return is.getPosition() == corr; }));
    }

private:
    void randomIslandGenerator(size_t amount)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::vector<int> map_(mapXsize * mapYsize);
        std::iota(std::begin(map_), std::end(map_), 0);
        std::shuffle(std::begin(map_), std::end(map_), gen);

        for (size_t i = 0; i < amount; i++)
            islands.push_back(Island(map_[i] % mapXsize, ((map_[i]) / mapXsize) % mapYsize));
    }

    size_t mapXsize;
    size_t mapYsize;
    std::vector<Island> islands;
    Island* currentPosition_;
};
