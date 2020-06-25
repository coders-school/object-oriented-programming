#pragma once
#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Island::Coordinates& coordinates);

private:
    void generateIsland(size_t howMany);
    Island* currentPosition_;
    std::vector<Island> islands_;
};
