#pragma once

#include <memory>
#include <vector>

#include "island.hpp"

constexpr size_t MAP_SIZE = 10;  // 10 x 10
constexpr size_t MAX_ISLANDS = 10;

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinate); // (const Island::Coordinates& coordinate)

private:
    std::vector<std::shared_ptr<Island>> islands_;
    Island* currentPosition_;
};
