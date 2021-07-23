#pragma once

#include <memory>
#include <random>
#include <vector>
#include "Island.hpp"

Island::Coordinates generatePosition();

class Map {
public:
    using IslandVec = std::vector<std::unique_ptr<Island>>;

    Map();

    const IslandVec& getIslandVec() const;
    Island* getCurrentPosition() const;
    Island* getIsland(const Island::Coordinates&) const;

    void setCurrentPosition(const Island::Coordinates& coordinates);

private:
    void fillWithRandomIslands();

    Island* currentPosition_;
    IslandVec islandVec_ = {};
};
