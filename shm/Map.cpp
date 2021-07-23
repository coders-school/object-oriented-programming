#include "Map.hpp"
#include <algorithm>

constexpr auto defaultIslandsNumber = 10u;
constexpr auto mapWidth = 10u;
constexpr auto mapHeight = 10u;

Island::coordinateType generateAxisPosition(size_t limit) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, limit);

    return distrib(gen);
}

Island::Coordinates generatePosition() {
    auto posX = generateAxisPosition(mapWidth);
    auto posY = generateAxisPosition(mapHeight);
    Island::Coordinates newCoordinate(posX, posY);
    return newCoordinate;
}

void Map::fillWithRandomIslands() {
    const size_t capacity = islandVec_.capacity();
    while (islandVec_.size() <= capacity) {
        Island::Coordinates newCoordinate = generatePosition();
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
    islandVec_.reserve(defaultIslandsNumber);
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
