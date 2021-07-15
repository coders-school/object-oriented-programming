#pragma once

#include <random>
#include <vector>
#include <memory>
#include "Island.hpp"

Island::coordinateType generatePosition();

class Map {
    using IslandVec = std::vector<std::unique_ptr<Island>>;

public:
    Map();
    const IslandVec& getIslandVec() const;
    Island* getCurrentPosition() const;
    Island* getIsland(const Island::Coordinates&);

private:
    Island* currentPosition_;
    IslandVec islandVec_ = {};
    void fillWithRandomIslands();
};
