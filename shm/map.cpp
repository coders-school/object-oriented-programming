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
                return posX == i.first && posY == i.second;
            })) {
            islands_.push_back(Island(posX, posY));
            isls--;
        }
    } while (isls > 0);
}
