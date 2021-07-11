#pragma once

#include <random>
#include <vector>
#include "Island.hpp"

class Map {
public:
    Map();
    const std::vector<Island>& getIslandVec() const;
    Island* getCurrentPosition() const;
    Island* getIsland(const Island::Coordinates&);

private:
    Island* currentPosition_;
    std::vector<Island> islandVec_;
    void fillWithRandomIslands();
};
