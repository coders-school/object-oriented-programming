#pragma once

#include "coordinates.hpp"
#include "island.hpp"

#include <memory>
#include <vector>

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& desiredCoordinate);
    
private:
    std::vector<Island> islandsOnMap_;
    Island* currentPosition_;
};
