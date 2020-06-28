#include "Map.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <set>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> getRandomWidth(0, MAP_WIDTH);
    std::uniform_int_distribution<> getRandomHeight(0, MAP_HEIGHT);
    std::set<std::pair<size_t, size_t>> uniquePositions;
    bool isUniquenessConditionMet = ((MAP_WIDTH + 1) * (MAP_HEIGHT + 1)) >= NUMBER_OF_ISLANDS;

    if (isUniquenessConditionMet) {
        while (uniquePositions.size() < NUMBER_OF_ISLANDS) {
            size_t x = getRandomWidth(gen);
            size_t y = getRandomHeight(gen);
            uniquePositions.insert({x, y});
        }
    } else {
        std::cerr << "Could not generate " << NUMBER_OF_ISLANDS << " unique islands with provided map size!";
    }

    std::for_each(uniquePositions.begin(),
                  uniquePositions.end(),
                  [](const auto& position) {
                      islands_.push_back(Island(position.first, position.second));
                  });
}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto island = std::find_if(islands_.begin(),
                               islands_.end(),
                               [&coordinates](const auto& el) {
                                   return el.getPosition() == coordinates;
                               });
    if (island == islands_.end()) {
        return nullptr;
    }
    return &(*island);
}
