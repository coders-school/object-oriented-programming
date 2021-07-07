#pragma once

#include "shm/inc/Island.hpp"

#include <vector>

constexpr size_t COORDINATE_MIN = 0;
constexpr size_t COORDINATE_MAX = 99;
constexpr size_t ISLANDS_COUNT = 10;

class Map {
public:
    Map();
    Island* getIsland(const Island::Coordinates&);

private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
