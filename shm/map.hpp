#pragma once

#include "coordinates.hpp"
#include "island.hpp"

#include <memory>
#include <vector>

class Map {
private:
    std::vector<Island> vecOfIslandOnMap_;
    Island* currentPosition_;
    
public:
    Map();
    Island* getIsland(const Coordinates& desiredCoordinate);
    
private:
    std::vector<std::unique_ptr<Island>> islandsOnMap_;
    Island* currentPosition_;
};
