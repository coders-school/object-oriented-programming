#include "Map.hpp"

#include <algorithm>
#include <cmath>
#include <random>

constexpr uint8_t islandsAmount = 10;
constexpr uint16_t axisX = 100;
constexpr uint16_t axisY = 100;

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> genPositionX(0, axisX);
    std::uniform_int_distribution<> genPositionY(0, axisY);
    islands_.reserve(islandsAmount);
    uint8_t counter{};
    std::vector<std::pair<uint16_t, uint16_t>> positionBefore;

    do {
        uint16_t genPosX = genPositionX(gen);
        uint16_t genPosY = genPositionY(gen);

        if (std::find_if(positionBefore.begin(), positionBefore.end(),
                         [genPosX, genPosY](const auto& position) {
                             return position.first == genPosX && position.second == genPosY;
                         }) == positionBefore.end()) {
            positionBefore.push_back(std::make_pair(genPosX, genPosY));
            islands_.push_back(Island(genPosX, genPosY));
            counter++;
        }

    } while (counter != islandsAmount);

    currentPosition_ = &islands_.front();
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto soughtIsland = std::find_if(islands_.begin(), islands_.end(),
                                     [&coordinate](const Island& island) {
                                         return coordinate == island.getPosition();
                                     });

    if (soughtIsland != islands_.end()) {
        return &*soughtIsland;
    }
    return nullptr;
}

uint16_t Map::getDistanceToIsland(Island* destination) const {
    return Coordinates::Distance(destination->getPosition(), currentPosition_->getPosition());
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}

void Map::Travel(Island* destination) {
    if (currentPosition_ == destination) {
        return;
    }

    currentPosition_ = destination;
}