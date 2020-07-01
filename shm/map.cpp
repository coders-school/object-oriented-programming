#include "map.hpp"

#include <algorithm>
#include <random>

constexpr int initialAmountOfIsland = 10;
constexpr int maxX = 10;
constexpr int maxY = 10;

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xesGen(0, maxX);
    std::uniform_int_distribution<> yesGen(0, maxY);
    islandsOnMap_.reserve(initialAmountOfIsland);

    for (auto islandCounter = 0; islandCounter < initialAmountOfIsland; ++islandCounter) {
        while (true) {
            int posX = xesGen(gen);
            int posY = yesGen(gen);
            if (std::none_of(islandsOnMap_.cbegin(), islandsOnMap_.cend(), [posX, posY](const auto& position) {
                                     return position.getCoordinates() == Coordinates(posX, posY);
                                     })) {           
                islandsOnMap_.push_back(Island(posX, posY));
                break;
            }
        }
    }
    currentPosition_ = &islandsOnMap_.front();
}

Island* Map::getIsland(const Coordinates& desiredCoordinates) {
    auto iCoordinate = std::find_if(islandsOnMap_.begin(), islandsOnMap_.end(), [desiredCoordinates](const auto& el) {
        return el.getCoordinates() == desiredCoordinates;
        });
    if (iCoordinate != islandsOnMap_.end()) {
        return &*iCoordinate;
    }
    return nullptr;
}
