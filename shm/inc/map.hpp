#pragma once

#include <vector>

#include "coordinates.hpp"
#include "island.hpp"

class Map {
private:
    std::vector<Island> islands_;
    Island* currentPosition_;

public:
    Island* getIsland(const Coordinates&);
};
