#include "map.hpp"

#include <algorithm>
#include <random>

Map::Map() {
    std::vector<unsigned int> posX(maxX);
    std::vector<unsigned int> posY(maxY);

    std::iota(posX.begin(), posX.end(), posX.begin());
    std::iota(posY.begin(), posY.end(), posY.begin());

    std::mt19937 gen(std::random_device{}());
    std::shuffle(posX.begin(), posX.end(), gen);
    std::shuffle(posY.begin(), posY.end(), gen);

    vecOfIslandOnMap_.reserve(initialAmountOfIsland);

    std::transform(posX.begin(),
                   posX.end(),
                   posY.begin(),
                   std::back_inserter(vecOfIslandOnMap_),
                   [](int x, int y) {
                       return std::make_pair(x, y);
                   });

    Island* getIsland(const Island::Coordinates& desiredCoordinate) {
        std::find_if(Island.cbegin(), Island.cend(), [desiredCoordinate](const auto& el) {
            return result};
        if (result != Island.end()) {
            return el.getCoordinates() == desiredCoordinates;
        }
        return desiredCoordinates;
    }
};
