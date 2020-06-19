#include "map.hpp"

#include <algorithm>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, initialAmountOfIsland);

    std::transform(posX.begin(),
                   posX.end(),
                   posY.begin(),
                   std::back_inserter(islandsOnMap_),
                   [](int x, int y) {
                       return std::make_pair(x, y);
                   });

    Island* getIsland(const Island::Coordinates& desiredCoordinate) {
        std::find_if(islandsOnMap_.begin(), islandsOnMap_.cend(), [desiredCoordinate](const auto& el) {
            if (el.getCoordinates != islandsOnMap_.end()) {
                return el.getCoordinates() == desiredCoordinates;
            }
            return 0;
        };
    }
};
