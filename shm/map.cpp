#include "map.hpp"

#include <algorithm>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, initialAmountOfIsland);

    for (auto islandCounter = 0; islandCounter < initialAmountOfIsland; ++islandCounter) {
        int posX = distrib(gen);
        int posY = distrib(gen);
        islandsOnMap_.push_back(std::unique_ptr<Island>(posX, posY));
    }  

    Island* getIsland(const Island::Coordinates& desiredCoordinate) {
        std::find_if(islandsOnMap_.begin(), islandsOnMap_.cend(), [desiredCoordinate](const auto& el) {
            if (el.getCoordinates != islandsOnMap_.end()) {
                return el.getCoordinates() == desiredCoordinates;
            }
            return 0;
        };
    }
};
