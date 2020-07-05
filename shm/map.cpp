#include "map.hpp"

#include <algorithm>
#include <random>

constexpr int initialAmountOfIsland = 10;
constexpr int maxX = 100;
constexpr int maxY = 100;

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

Island* Map::getCurrentPosition() {
    return currentPosition_;
}

std::ostream& operator<<(std::ostream& print, const Map& map) {
    print << "Map\n";
    std::for_each(map.islandsOnMap_.begin(), map.islandsOnMap_.end(), 
        [&print](const Island& island) {
            print << island.getCoordinates() << '\n';
        });
        return print;
}

int Map::getDistanceToIsland (Island* destination) {
    const int dist = Island::Coordinates::Distance(currentPosition_->getCoordinates(), 
                                                   destination->getCoordinates());
    return dist;
}

void Map::travel(Island* destination) {
    currentPosition_ = destination;
}