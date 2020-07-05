#include "Map.h"

#include <algorithm>
#include <random>

#include "Island.h"

Map::Map(Time* time) {
    std::random_device rd;
    std::mt19937 gen(rd());
    for (size_t i = 0; i < islandsCount; i++) {
        std::uniform_int_distribution<> distrib(0, mapSizeX);
        std::uniform_int_distribution<> distrib2(0, mapSizeY);
        size_t x;
        size_t y;
        do {
            x = distrib(gen);
            y = distrib2(gen);
        } while (getIsland(Coordinates(x, y)) != nullptr);
        Island island(x, y, time);
        islands_.push_back(island);
    };
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto it = std::find_if(islands_.begin(), islands_.end(), [coordinate](auto& i) { return i.getCoordinates() == coordinate; });

    if (it == islands_.end()) {
        return nullptr;
    }
    return std::addressof(*it);
}
