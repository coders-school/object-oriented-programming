#pragma once

#include <memory>
#include <vector>

#include "Coordinates.hpp"
#include "Island.hpp"

constexpr int minCoordinate = 0;
constexpr int maxCoordinate = 100;
constexpr int numberOfIslands = 10;

class Map {
public:
    Island* getIsland(const Coordinates& coordinate);

    Map();

private:
    std::vector<std::shared_ptr<Island>> islands_;
    Island* currentPosition_;
};
