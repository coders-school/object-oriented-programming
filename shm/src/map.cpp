#include "map.hpp"

#include <algorithm>
#include <random>
#include <string>

constexpr size_t numOfIslands = 10;
constexpr uint16_t mapX = 100;
constexpr uint16_t mapY = 100;

Map::Map() {
    islands_.reserve(numOfIslands);
    creaIsland(numOfIslands);
}

void Map::creaIsland(size_t numb) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xGener(0, mapX);
    std::uniform_int_distribution<> yGener(0, mapY);

    for (size_t i = 0; i < numOfIslands; i++) {
        uint16_t newX;
        uint16_t newY;
        do {
            newX = xGener(gen);
            newY = yGener(gen);
        } while (std::any_of(islands_.begin(), islands_.end(), [=](auto island) {
            return island.getPosition() == Island::Coordinates(newX, newY);
        }));
        islands_.emplace_back(newX, newY);
    }
}

Island* Map::getIsland(const Island::Coordinates& coordinates) {
    auto fIsland = std::find_if(std::begin(islands_), std::end(islands_),
                                [&coordinates](const auto& island) {
                                    return island.getPosition() == coordinates;
                                });
    if (fIsland != std::end(islands_)) {
        return &*fIsland;
    }
    return nullptr;
}
