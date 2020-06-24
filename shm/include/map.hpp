#pragma once

#include <vector>

#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinate);

private:
    std::vector<Island> Islands_;
    Island* currentPosition_;
};
