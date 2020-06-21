#pragma once

#include <random>
#include <vector>
#include <algorithm>
#include "Island.hpp"

constexpr size_t MAX_X = 32;
constexpr size_t MAX_Y = 32;

struct IslandGenerator
{
    IslandGenerator() {}
    IslandGenerator(Coordinates start, Coordinates end) {}

    Island getRandomIsland()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, MAX_Y);
        return Island(distrib(gen), distrib(gen));
    }
    void generate(std::vector<Island>& islands, int amount);

    islands.reserve(amount);
    std::generate(std::begin(islands), std::end(islands), getRandomIsland);
};

class Map
{

public:
    Map() {}

private:
    std::vector<Island> islands;
    Island* currentPosition_;
};
