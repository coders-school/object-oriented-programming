#pragma once

#include "Island.hpp"
#include <vector>

constexpr auto NUMBER_OF_ISLANDS = 10;
constexpr auto MAP_WIDTH = 100;
constexpr auto MAP_HEIGHT = 100;

class Map {
public:
    Map();

private:
    std::vector<Island&> islands_;
    Island* currentPosition_;
};
