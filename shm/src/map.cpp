#include "map.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, MAP_SIZE);

    auto isls = MAX_ISLANDS;
    do {
        auto posX = (size_t)distrib(gen);
        auto posY = (size_t)distrib(gen);
        if (std::none_of(islands_.begin(), islands_.end(), [posX, posY](auto& i) {
                return i->getPosition() == Coordinates(posX, posY);
            })) {
            islands_.push_back(std::make_shared<Island>(posX, posY));
            isls--;
        }
    } while (isls > 0);

    currentPosition_ = islands_.front();
}

std::shared_ptr<Island> Map::getCurrentPosition() const {
    return currentPosition_;
}

std::shared_ptr<Island> Map::getIsland(const Coordinates& coordinate) const {
    auto itr = std::find_if(islands_.begin(), islands_.end(), [&coordinate](auto& i) {
        return i->getPosition() == coordinate; } );
    if (itr == islands_.end()) {
        return nullptr;
    }
    return *itr;
}

size_t Map::getDistanceToIsland(std::shared_ptr<Island> destination) const {
    auto xCurr = currentPosition_->getPosition().getPositionX();
    auto yCurr = currentPosition_->getPosition().getPositionY();
    auto xDest = destination->getPosition().getPositionX();
    auto yDest = destination->getPosition().getPositionY();
    auto xLength = std::max(xCurr, xDest) - std::min(xCurr, xDest);
    auto yLength = std::max(yCurr, yDest) - std::min(yCurr, yDest);
    return std::floor(std::hypot(xLength, yLength));
}

void Map::travel(std::shared_ptr<Island> destination) {
    currentPosition_ = destination;
}

std::ostream& operator<<(std::ostream& out, const Map& map) {
    for (const auto& i : map.islands_) {
        out << "Island [" << i->getPosition().getPositionX() << ", " << i->getPosition().getPositionY() << "]";
        out << " Distance: " << map.getDistanceToIsland(i) << "\n";
    }
    return out;
}
