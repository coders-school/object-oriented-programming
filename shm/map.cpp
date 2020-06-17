#include "map.hpp"

#include <algorithm>
#include <random>
#include <vector>

#include "island.hpp"

const int total_islands = 10;
const size_t map_size = 10;  // [-10, 10]
constexpr size_t total_map_fields = map_size * map_size;

Map::Map() {
    islands_.reserve(total_islands);
    addIsland(total_islands);
}

void Map::addIsland(size_t how_many) {
    std::random_device rd;   //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());  //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, map_size - 1);

    for (size_t i = 0; i < how_many; i++) {
        int new_x;
        int new_y;
        do {
            new_x = distrib(gen);
            new_y = distrib(gen);
        } while (std::any_of(islands_.begin(), islands_.end(), [=](auto island) {
            return island.getPosition() == Coordinates(new_x, new_y);
        }));
        islands_.emplace_back(Island(new_x, new_y));
    }
}
