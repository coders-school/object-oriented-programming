#pragma once

#include "Island.hpp"
#include <vector>

class Map {
private:
    Island* currentPosition_ {nullptr};
    std::vector<Island> islandsLocations_;
public:
    void setCurrentPosition(Island* const currentPosition);
    void addIsland(const Island& newIsland);
    Island* getIsland(const Coordinates& coordinate);
};

