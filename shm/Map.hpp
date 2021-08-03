#pragma once

#include <memory>
#include <random>
#include <vector>
#include "Island.hpp"

constexpr auto defaultIslandsNumber = 10u;
constexpr auto mapWidth = 10u;
constexpr auto mapHeight = 10u;

class Map {
public:
    using IslandVec = std::vector<std::unique_ptr<Island>>;

    Island::Position generatePosition(Island::CoordinateType, Island::CoordinateType);

    Map();

    const IslandVec& getIslandVec() const;
    Island* getCurrentPosition() const;
    Island* getIsland(const Island::Position&) const;

    void setCurrentPosition(const Island::Position&);

private:
    void fillWithRandomIslands();

    Island* currentPosition_;
    IslandVec islandVec_ = {};
};
