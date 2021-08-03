#include "Map.hpp"
#include <algorithm>
#include "RandomNumberGenerator.hpp"

Island::Position Map::generatePosition(Island::CoordinateType coordinateX, Island::CoordinateType coordinateY) {
    Island::Position newPosition(coordinateX, coordinateY);
    return newPosition;
}

void Map::fillWithRandomIslands() {
    islandVec_.reserve(defaultIslandsNumber);
    const size_t capacity = islandVec_.capacity();
    RandomNumberGenerator generatorX(1, mapWidth);
    RandomNumberGenerator generatorY(1, mapHeight);
    while (islandVec_.size() <= capacity) {
        auto coordinateX = generatorX.nextRandomNumber();
        auto coordinateY = generatorY.nextRandomNumber();
        Island::Position newPosition = generatePosition(coordinateX, coordinateY);
        auto check = std::find_if(islandVec_.begin(), islandVec_.end(),
                                  [&newPosition](const std::unique_ptr<Island>& island) {
                                      return island->getPosition() == newPosition;
                                  });
        if (check == islandVec_.end()) {
            auto newIsland = std::make_unique<Island>(newPosition);
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

Island* Map::getIsland(const Island::Position& position) const {
    auto it = std::find_if(islandVec_.begin(), islandVec_.end(),
                           [&position](const std::unique_ptr<Island>& island) {
                               return island->getPosition() == position;
                           });
    if (it != islandVec_.end()) {
        return it->get();
    }
    return nullptr;
}

void Map::setCurrentPosition(const Island::Position& position) {
    currentPosition_ = getIsland(position);
}
