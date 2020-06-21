#pragma once
#include <vector>

#include "island.hpp"

class Map {
public:
    Map();

private:
    void generateIsland(size_t howMany);
    Island* currentPosition_;
    std::vector<Island> islands_;
};
