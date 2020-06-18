#pragma once
#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    void addIsland(size_t howMany);

private:
    Island* currentPosition_;
    std::vector<Island> islands_;
};
