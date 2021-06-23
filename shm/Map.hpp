#pragma once

#include <random>
#include <vector>
#include "Island.hpp"

constexpr auto defaultIslandsNumber = 10u;

class Map {
    std::vector<Island> islandVec_;
    Island* currentPosition_;

public:
    Map();
    const std::vector<Island>& getIslandVec() const;
    Island* getCurrentPosition() const;
    Island* getIsland(const Island::Coordinates&);

private:
    void fillWithRandomIslands();
};
