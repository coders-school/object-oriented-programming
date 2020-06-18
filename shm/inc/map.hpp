#pragma once

#include <vector>

#include "coordinates.hpp"
#include "island.hpp"

class Map {
public:
    Island* getIsland(const Coordinates& coordinates);
    
private:
    std::vector<Island> islands_;
    Island* currentPosition_;
};
