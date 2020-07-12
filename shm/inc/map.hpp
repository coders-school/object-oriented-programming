#pragma once

#include "island.hpp"

#include <vector>

class Map {
public:
    Map();
    virtual ~Map();
    Island* getIsland(const Coordinates& coordinates);
    void printMap();
    void travel(Island* island);
    size_t getDistanceToIsland(Island* destination) const;
    Island* getCurrentPosition() const;

private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
