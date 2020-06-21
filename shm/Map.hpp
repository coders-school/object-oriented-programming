#pragma once

#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Island.hpp"

class Map
{

public:
    Map() : mapXsize(10), mapYsize(10) { randomIslandGenerator(20); }
    Map(int islandsAmount) { randomIslandGenerator(islandsAmount); }
    Map(int sizeY, int sizeX, int islandsAmount) : mapXsize(sizeY), mapYsize(sizeX)
    {
        randomIslandGenerator(islandsAmount);
    }

    std::vector<Island> getIslands() { return islands; }

private:

    //std::vector<int> buildCoordinates(
    

    void randomIslandGenerator(int amount)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        

        std::vector<int> x(mapXsize);
        std::iota(std::begin(x), std::end(x), 0);
        std::shuffle(std::begin(x), std::end(x), gen);

        std::vector<int> y(mapYsize);
        std::iota(std::begin(y), std::end(y), 0);
        std::shuffle(std::begin(y), std::end(y), gen);

        for (int i = 0; i < amount; i++)
            {
            islands.push_back(Island(x[i], y[i]));
            }
    }

    size_t mapXsize;
    size_t mapYsize;
    std::vector<Island> islands;
    Island* currentPosition_;
};
