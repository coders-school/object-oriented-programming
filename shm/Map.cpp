#include "Map.hpp"
#include <algorithm>
#include "RandomNumberGenerator.hpp"

constexpr auto defaultIslandsNumber = 10u;
constexpr auto mapWidth = 10u;
constexpr auto mapHeight = 10u;

Island::Coordinates Map::generatePosition(Island::coordinateType coordinateX, Island::coordinateType coordinateY) {
    Island::Coordinates newCoordinate(coordinateX, coordinateY);
    return newCoordinate;
}

void Map::fillWithRandomIslands() {
    islandVec_.reserve(defaultIslandsNumber);
    const size_t capacity = islandVec_.capacity();
    RandomNumberGenerator generatorX;
    RandomNumberGenerator generatorY;
    while (islandVec_.size() <= capacity) {
        auto posX = generatorX.nextRandomNumber();
        auto posY = generatorY.nextRandomNumber();
        Island::Coordinates newCoordinate = generatePosition(posX, posY);
        auto check = std::find_if(islandVec_.begin(), islandVec_.end(),
                                  [&newCoordinate](const std::unique_ptr<Island>& island) {
                                      return island->getPosition() == newCoordinate;
                                  });
        if (check == islandVec_.end()) {
            auto newIsland = std::make_unique<Island>(newCoordinate);
            islandVec_.push_back(std::move(newIsland));
        }
    }
}

Map::Map() {
    fillWithRandomIslands();
}

const Map::IslandVec& Map::getIslandVec() const {
    return islandVec_;
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}

Island* Map::getIsland(const Island::Coordinates& coordinate) const {
    auto it = std::find_if(islandVec_.begin(), islandVec_.end(),
                           [&coordinate](const std::unique_ptr<Island>& island) {
                               return island->getPosition() == coordinate;
                           });
    if (it != islandVec_.end()) {
        return it->get();
    }
    return nullptr;
}

void Map::setCurrentPosition(const Island::Coordinates& coordinates) {
    currentPosition_ = getIsland(coordinates);
}
