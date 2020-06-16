#pragma once

#include <vector>

#include "island.hpp"

constexpr size_t MAP_SIZE = 10;  // 10 x 10
constexpr size_t MAX_ISLANDS = 10;

class Map {
public:
    Map();

private:
    std::vector<Island&> islands_;
    Island* currentPosition_;
};
