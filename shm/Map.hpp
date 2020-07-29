#pragma once

#include <ostream>
#include <vector>

#include "Island.hpp"

constexpr size_t amountOfIslands = 10;
constexpr size_t minPositionXY = 0;
constexpr size_t maxPositionXY = 10;

class Map {
private:
    void generateIslands(int numOfIslandsToGenerate);
    Island* currentPosition_{nullptr};
    std::vector<Island> islandsLocations_;
    friend void populateMapScreen(std::ostream& out, const Map& map);

public:
    Map();
    void setCurrentPosition(Island* const currentPosition);
    void addIsland(const Island& newIsland);
    Island* getIsland(const Coordinates& coordinate);
    friend std::ostream& operator<<(std::ostream& out, const Map& map);
    size_t getDistanceToIsland(Island* destination);
};
