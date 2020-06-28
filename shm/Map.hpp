#pragma once

#include <vector>
#include "Island.hpp"

constexpr auto NUMBER_OF_ISLANDS = 10;
constexpr auto MAP_WIDTH = 100;
constexpr auto MAP_HEIGHT = 100;

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinates);

private:
    std::vector<Island&> islands_;
    Island* currentPosition_;
};
