#pragma once

#include <random>
#include <vector>
#include <memory>
#include "Island.hpp"

constexpr auto defaultIslandsNumber = 10u;

class Map {
    using IslandVec = std::vector<std::unique_ptr<Island>>;
    IslandVec islandVec_;
    Island* currentPosition_;

public:
    Map();
    const IslandVec& getIslandVec() const;
    Island* getCurrentPosition() const;
    Island* getIsland(const Island::Coordinates&);

private:
    void fillWithRandomIslands();
};
