#pragma once
#include <vector>

#include "Coordinates.h"
#include "Island.h"

const int islandsCount = 10;
const int mapSizeX = 10;
const int mapSizeY = 10;

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinate);

private:
    std::vector<Island> islands_;
    Island* currentPosition_;
};
