#pragma once
#include <vector>
#include <functional>
#include <random>
#include <memory>
#include "coordinates.hpp"
#include "island.hpp"
class Map {
public:
    Map();
    Island* const getIsland(const Coordinates& coordinate);

private:
    Coordinates getRandomCoordinates();
    const int maxWidth_ = 99;
    const int maxHeight_ = 99;
    const int islandsQuantity_ = 10;
    std::vector<Island> islands_;
    Island* currentPostion_;
};