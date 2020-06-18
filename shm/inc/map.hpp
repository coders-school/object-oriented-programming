#pragma once

#include <vector>

#include "coordinates.hpp"
#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinates);

private:
    void generateIslands();
    std::vector<Island> islands_;
    Island* currentPosition_;
};
