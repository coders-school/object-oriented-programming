#include "Map.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <utility>

constexpr size_t NUMBER_OF_ISLANDS = 10;
constexpr size_t MAP_SIZE = 100;

Map::Map() {
    islands_.reserve(NUMBER_OF_ISLANDS);
    fillMapWithIslands();
}

Coordinates Map::generateCoordinates() {
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::uniform_real_distribution<> distrib(0, MAP_SIZE);
    Coordinates coordinates(distrib(gen), distrib(gen));
    return coordinates;
}

void Map::fillMapWithIslands() {
    for (int i = 0; i < NUMBER_OF_ISLANDS; i++) {
        Coordinates coordinates = generateCoordinates();
        while (getIsland(coordinates)) {
            Coordinates coordinates = generateCoordinates();
        }
        auto island = std::make_unique<Island>(coordinates);
        islands_.push_back(std::move(island));
        std::cout << "done"
                  << "\n";
    }
}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto itr = std::find_if(islands_.begin(), islands_.end(),
                            [&coordinates](const std::unique_ptr<Island>& island) {
                                return island->getPosition() == coordinates;
                            });
    if (itr != islands_.end()) {
        return (*itr).get();
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& out, const Map& map) {
    int i{1};
    for (const auto& island : map.islands_) {
        if (island) {
            out << i++ << island->getPosition()  << '\n';
        }
    }
    std::cout << "\n";
    return out;
}