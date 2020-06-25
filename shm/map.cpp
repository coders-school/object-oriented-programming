#include "map.hpp"

#include <algorithm>
#include <random>
#include <vector>

constexpr size_t totalIslands = 10;
constexpr size_t mapWidth = 20;
constexpr size_t mapHeight = 10;

Map::Map() {
    islands_.reserve(totalIslands);
    generateIsland(totalIslands);
}

void Map::generateIsland(size_t howMany) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xDistrib(0, mapWidth);
    std::uniform_int_distribution<> yDistrib(0, mapHeight);

    for (size_t i = 0; i < howMany; i++) {
        int newX;
        int newY;
        do {
            newX = xDistrib(gen);
            newY = yDistrib(gen);
        } while (std::any_of(islands_.begin(), islands_.end(), [=](auto island) {
            return island.getPosition() == Island::Coordinates(newX, newY);
        }));
        islands_.emplace_back(Island(newX, newY));
    }
}
Island* Map::getIsland(const Island::Coordinates& coordinate) {
    Island* findedIsland;
    for (auto& el : islands_) {
        if (el.getPosition() == coordinate) {
            findedIsland = &el;
        }
    }
    return findedIsland;
}
