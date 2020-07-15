#include "map.hpp"

#include <algorithm>
#include <random>

#include "locators.hpp"
#include "time.hpp"

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 255);
    for (size_t i = 0; i < 10; ++i) {
        Island temp(distrib(gen), distrib(gen));
        while (std::any_of(Islands_.begin(), Islands_.end(), [temp](const Island& islnd) {
            return islnd.getCoordinates() == temp.getCoordinates();
        })) {
            temp = Island(distrib(gen), distrib(gen));
        }
        Islands_.push_back(temp);
    }
    currentPosition_ = &Islands_[0];
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto result =
        std::find_if(Islands_.begin(), Islands_.end(), [coordinate](const Island& islnd) {
            return islnd.getCoordinates() == coordinate;
        });
    if (result == Islands_.end()) {
        return nullptr;
    }
    return &(*result);
}

size_t Map::getDistanceToIsland(Island* destination) {
    destination->getCoordinates();
    currentPosition_->getCoordinates();
    return Coordinates::distance(destination->getCoordinates(), currentPosition_->getCoordinates());
}

void Map::travel(Island* destination) {
    if (destination == currentPosition_) {
        return;
    }
    currentPosition_ = destination;
}
