#include "map.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "island.hpp"

const int total_islands = 10;
const size_t map_size = 20;  // [-10, 10]
constexpr size_t total_map_fields = map_size * map_size;

Map::Map() {
    islands_.reserve(total_islands);
    addIsland(total_islands);
}

void Map::addIsland(int how_many) {
    std::vector<int> coords_occupied(how_many);  // can be optimalised with std::set<int>
    std::random_device rd;                       //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());                      //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, total_map_fields - 1);

    for (size_t i = 0; i < how_many; i++) {
        int new_position;
        do {
            new_position = distrib(gen);
        } while (std::find(coords_occupied.begin(), coords_occupied.end(), new_position) != coords_occupied.end());
        coords_occupied.push_back(new_position);
        islands_.emplace_back(Island(new_position % map_size, new_position / map_size));
    }
}

int main() {
    Map test_map;
    // std::cout<< test_map.a;
    std::for_each(test_map.islands_.begin(), test_map.islands_.end(), [](auto isl) {
        std::cout << isl.position_.positionX_ << " " << isl.position_.positionY_ << "\n";
    });
}