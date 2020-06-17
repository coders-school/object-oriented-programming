#pragma once
#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    void addIsland(size_t how_many);
    std::vector<Island> islands_;

private:
    Island* currentPosition_;
};
