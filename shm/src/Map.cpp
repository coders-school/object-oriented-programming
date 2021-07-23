#include "shm/inc/Map.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>

#include "shm/inc/Time.hpp"

Map::Map(Time* time) {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<size_t> distribution{
        COORDINATE_MIN, COORDINATE_MAX
    };
    countRecordsInFile(storeSize_);
    islands_.reserve(ISLANDS_COUNT);
    while (islands_.size() != ISLANDS_COUNT) {
        auto generatedIslandCoords{
            Island::Coordinates(distribution(generator),
                                distribution(generator))
        };
        auto result = std::find_if(islands_.cbegin(),
                                   islands_.cend(),
                                   [&](const Island& island) {
                                       return island.getCoordinates() ==
                                               generatedIslandCoords;
                                   });
        if (result == islands_.end()) {
            islands_.push_back(Island(generatedIslandCoords, storeSize_, time));
        }
    }
}

Island* Map::getIsland(const Island::Coordinates& coordinates) {
    auto island_it = std::find_if(islands_.begin(), islands_.end(),
                                 [&coordinates](auto& island) {
                                     return island.getCoordinates() == coordinates;
                                 });
    return island_it != islands_.end()
           ? std::addressof(*island_it)
           : nullptr;
}

void Map::countRecordsInFile(size_t &counter) {
    std::string line;
    std::fstream file;
    file.open("settings/items.txt", std::ios::in);
    if (file.fail()) {
        std::cout << "File not exist map\n";
    }
    while (getline(file, line)) {
        counter++;
    }
    file.close();
}