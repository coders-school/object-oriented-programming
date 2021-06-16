#pragma once

#include <random>
#include <vector>
#include "Island.hpp"
class Map {
    std::vector<Island> islandVec_;
    Island* currentPosition_;

public:
    Map();
    std::vector<Island> getIslandVec() const;
    Island* getCurrentPosition() const;
    Island* getIsland(const Island::Coordinates&);
};
