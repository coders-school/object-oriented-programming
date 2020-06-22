#pragma once

#include "Island.hpp"
#include <vector>

constexpr size_t amountOfIslands = 10;
constexpr size_t minPositionXY = 0;
constexpr size_t maxPositionXY = 10;

class Map {
private:
    void generateIslands(int numOfIslandsToGenerate);
    Island* currentPosition_ {nullptr};
    std::vector<Island> islandsLocations_;
    
public:
    Map();
    void setCurrentPosition(Island* const currentPosition);
    void addIsland(const Island& newIsland);
    Island* getIsland(const Coordinates& coordinate);
};
