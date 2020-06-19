#include "map.hpp"

#include <algorithm>
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
                return i.get()->getPosition() == Coordinates(posX, posY);
            })) {
            islands_.push_back(std::make_shared<Island>(posX, posY));
            isls--;
        }
    } while (isls > 0);
}

std::shared_ptr<Island> Map::getIsland(const Coordinates& coordinate) {
    auto itr = std::find_if(islands_.begin(), islands_.end(), [&coordinate](auto& i) {
        return i->getPosition() == coordinate; } );
    if (itr == islands_.end()) {
        return nullptr;
    }
    return *itr;
}
