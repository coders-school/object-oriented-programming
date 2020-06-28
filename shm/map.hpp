#pragma once

#include <vector>

#include "island.hpp"

constexpr size_t totalIslands = 10;
constexpr size_t mapWidth = 20;
constexpr size_t mapHeight = 10;

class Map {
public:
    Map();
    Island* getIsland(const Island::Coordinates& coordinates);

    // for testing
    std::vector<Island> getIslands_() const { return islands_; };

private:
    Island* currentPosition_{};
    std::vector<Island> islands_{};

    void generateIsland(size_t howMany);
};
