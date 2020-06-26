#include "Map.hpp"

#include <algorithm>
#include <memory>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minPositionXY, maxPositionXY);

    _vecOfIslands.reserve(numberOfIslands);

    while (_vecOfIslands.size() < numberOfIslands) {
        int positionX = distrib(gen);
        int positionY = distrib(gen);

        if (std::none_of(_vecOfIslands.begin(), _vecOfIslands.end(),
                         [=](auto& i) {
                             return i.getPosition() == Coordinates(positionX, positionY);
                         })) {
            _vecOfIslands.push_back(Island(positionX, positionY));
        }
    }
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto itr = std::find_if(_vecOfIslands.begin(), _vecOfIslands.end(),
                            [&](auto& i) {
                                return i.getPosition() == coordinate;
                            });

    if (itr == _vecOfIslands.end())
        return {};

    return std::addressof(*itr);
}
