#include "map.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

constexpr size_t MIN_COORDINATE = 0;
constexpr size_t MAX_COORDINATE = 10;
constexpr size_t INITIAL_ISLAND_NUM = 10;

Map::Map() {
    std::random_device randDevice;
    std::mt19937 gen(randDevice());
    std::uniform_int_distribution<> distrib(MIN_COORDINATE,
                                            MAX_COORDINATE);

    while (vectorOfIslands_.size() != INITIAL_ISLAND_NUM) {
        size_t posX = distrib(gen);
        size_t posY = distrib(gen);

        auto it = std::find_if(vectorOfIslands_.begin(),
                               vectorOfIslands_.end(),
                               [=](const Island &island) -> bool {
                                   return (island.getPosition() ==
                                           Coordinates(posX, posY));
                               });
        if (it == vectorOfIslands_.end()) {
            vectorOfIslands_.push_back(Island(posX, posY));
        }
    }
    currentPosition_ = &(vectorOfIslands_.at(0));
}

Map::~Map() {}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto it = std::find_if(vectorOfIslands_.begin(),
                            vectorOfIslands_.end(),
                            [&](auto& el) {
                                return el.getPosition() == coordinates;
                            });
    if (it != vectorOfIslands_.end()) {
        return std::addressof(*it);
    }
    return nullptr;
}

void Map::printMap() {
    std::cout << "\nNumber of Islands: " << vectorOfIslands_.size() << "\n";
    for (const auto &el : vectorOfIslands_) {
        std::cout << "Coordinate (X, Y): "
                  << "(" << el.getPosition().getPositionX() << ", "
                  << el.getPosition().getPositionY() << ")\n";
    }
}

void Map::travel(Island* island) {
    currentPosition_ = island;
}

size_t Map::getDistanceToIsland(Island* destination) const {
    std::cout << "\nTravelling from ("
              << currentPosition_->getPosition().getPositionX() << ", "
              << currentPosition_->getPosition().getPositionY() << ") to ("
              << destination->getPosition().getPositionX() << ", "
              << destination->getPosition().getPositionY() << ")\n";

    auto xCurr = currentPosition_->getPosition().getPositionX();
    auto yCurr = currentPosition_->getPosition().getPositionY();
    auto xDest = destination->getPosition().getPositionX();
    auto yDest = destination->getPosition().getPositionY();
    auto xLength = std::max(xCurr, xDest) - std::min(xCurr, xDest);
    auto yLength = std::max(yCurr, yDest) - std::min(yCurr, yDest);

    return static_cast<size_t>(std::floor(std::hypot(xLength, yLength)));
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}
