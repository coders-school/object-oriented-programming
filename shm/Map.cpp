#include "Map.hpp"

#include <algorithm>
#include <memory>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(randomNumberStart, maxPositionXY);
    _vecOfIslands.reserve(numberOfIslands);
    int notRepeatedPositions = 0;
    while (notRepeatedPositions != 10) {
        int positionX = distrib(gen);
        int positionY = distrib(gen);
        if (std::none_of(_vecOfIslands.begin(), _vecOfIslands.end(), [positionX, positionY](auto& i) {
                return i.getPosition() == Coordinates(positionX, positionY);
            })) {
            _vecOfIslands.emplace_back(Island(positionX, positionY));
            notRepeatedPositions++;
        }
    }
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto itr = std::find_if(_vecOfIslands.begin(), _vecOfIslands.end(), [&coordinate](auto& i) { return i.getPosition() == coordinate; });
    return std::addressof(*itr);
}
