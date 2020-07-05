#pragma once

#include "island.hpp"

#include <vector>

class Map {
public:
    Map();
    virtual ~Map();
    Island *getIsland(const Coordinates& coordinates);
    void printMap();

private:
    std::vector<Island> vectorOfIslands_;
    Island *currentPosition_;
};