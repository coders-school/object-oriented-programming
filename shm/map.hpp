#pragma once

#include <memory>
#include <ostream>
#include <vector>

#include "coordinates.hpp"
#include "island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& desiredCoordinate);
    Island* getCurrentPosition();
    friend std::ostream& operator<<(std::ostream& print, const Map& map);
    int getDistanceToIsland (Island* destination);
    void travel(Island* destination);
    
private:
    std::vector<Island> islandsOnMap_;
    Island* currentPosition_;
};
