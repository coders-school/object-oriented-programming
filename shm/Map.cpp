#include "Map.hpp"

#include <algorithm>
#include <memory>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(randomNumberStart, maxPositionXY);
    vecOfIslands_.reserve(numberOfIslands);
    int notRepeatedPositions = 0;
    while (notRepeatedPositions != 10) {
        int positionX = distrib(gen);
        int positionY = distrib(gen);
        if (std::none_of(vecOfIslands_.begin(), vecOfIslands_.end(), [positionX, positionY](auto& i) {
                return i.getPosition() == Coordinates(positionX, positionY);
            })) {
            vecOfIslands_.emplace_back(Island(positionX, positionY));
            notRepeatedPositions++;
        }
    }
}
