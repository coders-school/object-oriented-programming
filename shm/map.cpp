#include "map.hpp"

#include <algorithm>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xesGen(0, maxX);
    std::uniform_int_distribution<> yesGen(0, maxY);

    for (auto islandCounter = 0; islandCounter < initialAmountOfIsland; ++islandCounter) {
        while (true) {
            int posX = xesGen(gen);
            int posY = yesGen(gen);
            if (std::none_of(islandsOnMap_.cbegin(), islandsOnMap_.cend(), [posX, posY](const auto& position) {
                                     return position.first == posX && position.second == posY;
                                     })) {           
                islandsOnMap_.push_back(Island(posX, posY));
                break;
            }
        }
    }
};

Island* Map::getIsland(const Coordinates& desiredCoordinates) {
    auto iCoordinate = std::find_if(islandsOnMap_.begin(), islandsOnMap_.end(), [desiredCoordinates](const auto& el) {
        return el->Island::getCoordinates() == desiredCoordinates;
        });
    if (iCoordinate != islandsOnMap_.end()) {
        return &*iCoordinate;
    }
    return nullptr;
}
