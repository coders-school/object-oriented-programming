#pragma once
#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    void addIsland(int how_many);
    std::vector<Island> islands_;

private:
    Island* currentPosition_;
};