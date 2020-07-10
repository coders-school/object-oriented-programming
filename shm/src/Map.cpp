#include "Map.hpp"

#include <algorithm>
#include <random>

#include "Coordinates.hpp"
#include "Island.hpp"

constexpr int minCoordinate = 0;
constexpr int maxCoordinate = 100;
constexpr int numberOfIslands = 10;

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minCoordinate, maxCoordinate);

    islands_.reserve(numberOfIslands);
    bool coordinatesAreFree;

    while (islands_.size() != numberOfIslands) {
        auto tempX = static_cast<size_t>(distrib(gen));
        auto tempY = static_cast<size_t>(distrib(gen));

        bool coordinatesAreFree = std::none_of(begin(islands_), end(islands_), [tempX, tempY](const Island& island) {
            return !(island.getPosition() == Coordinates(tempX, tempY));
        });

        if (coordinatesAreFree) {
            islands_.push_back(std::make_shared<Island>(Island(tempX, tempY)));
        }
    }
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto search = std::find(begin(islands_), end(islands_), [&coordinate](const std::shared_ptr<Island>& island){
        return island->getPosition() == coordinate;
    });
    if (search != end(islands_)) {
        return search->get();
    }
    return nullptr;
}
