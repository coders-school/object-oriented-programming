#pragma once

#include "Island.hpp"

#include <memory>
#include <vector>

class Map {
public:
    Map();
    Map(size_t sizeX, size_t sizeY, size_t islandAmount);

private:
    void islandGenerator(size_t amount);
    Island* getIsland(const Coordinates& coordinates);

    size_t sizeX_;
    size_t sizeY_;
    std::vector<Island> islandsArrangement_;
    std::shared_ptr<Island> currentPosition_{};
};