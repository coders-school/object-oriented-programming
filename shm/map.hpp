#pragma once

#include <memory>
#include <vector>

#include "coordinates.hpp"
#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& desiredCoordinate);
    Island* getCurrentPosition();
    
private:
    std::vector<Island> islandsOnMap_;
    Island* currentPosition_;
};
