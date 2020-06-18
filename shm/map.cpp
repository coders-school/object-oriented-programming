#include "map.hpp"

#include <algorithm>
#include <random>
#include <vector>

constexpr int totalIslands = 10;
constexpr size_t mapWidth = 20;
constexpr size_t mapHeight = 10;

Map::Map() {
    islands_.reserve(totalIslands);
    addIsland(totalIslands);
}

void Map::addIsland(size_t howMany) {
    std::random_device rd;   //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());  //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> xDistrib(0, mapWidth);
    std::uniform_int_distribution<> yDistrib(0, mapHeight);

    for (size_t i = 0; i < howMany; i++) {
        int newX;
        int newY;
        do {
            newX = xDistrib(gen);
            newY = yDistrib(gen);
        } while (std::any_of(islands_.begin(), islands_.end(), [=](auto island) {
            return island.getPosition() == Coordinates(newX, newY);
        }));
        islands_.emplace_back(Island(newX, newY));
    }
}
