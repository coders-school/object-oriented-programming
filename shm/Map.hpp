#pragma once
#include <vector>
#include "island.hpp"
#include <random>
#include <algorithm>
#include <utility>
#include <iostream>
#include "coordinates.hpp"

constexpr size_t COORDINATE_MIN = 0;
constexpr size_t COORDINATE_MAX = 99;
constexpr size_t ISLANDS_COUNT = 10;

class Map {
public:
    Map();
    void DebugPrintIsland();
private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(std::vector<Coordinates>, Coordinates);
};
