#pragma once

#include "Island.hpp"
#include <vector>

constexpr size_t amountIslands = 10;
constexpr size_t heightIsland = 10;
constexpr size_t widthIsland = 10;

class Map {
private:
    void generateIslands();
    Island* currentPosition_ {nullptr};
    std::vector<Island> islandsLocations_;
public:
    Map();
    void setCurrentPosition(Island* const currentPosition);
    void addIsland(const Island& newIsland);
    Island* getIsland(const Coordinates& coordinate);
};

