#include "map.hpp"

#include <iostream>
#include <map>
#include <random>
#include <string>

Map::Map(Time* time) : time_(time) {
    allIslands.reserve(NUM_OF_ISLANDS);

    std::map<std::string, int> repsChecker;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(MAP_RND_DISTRIBUTION_MIN, MAP_RND_DISTRIBUTION_MAX);

    bool coordinateExist = false;
    int32_t positionX = 0;
    int32_t positionY = 0;
    std::string coordinateXY = "";

    for (std::size_t i = 0; i < NUM_OF_ISLANDS; ++i) {
        do {
            positionX = distrib(gen);
            positionY = distrib(gen);

            coordinateXY = std::string(std::to_string(positionX) + std::to_string(positionY));
            auto tryInsert = repsChecker.emplace(coordinateXY, 0);
            coordinateExist = tryInsert.second;

        } while (!coordinateExist);

        allIslands.push_back(Island(Coordinates(positionX, positionY), time_));
        allIslands[i].createStore();
    }
}

Island* Map::getIsland(const Coordinates& coordinate) {
    for (Island& island : allIslands) {
        if (island.getPosition() == coordinate) {
            return &island;
        }
    }
    return nullptr;
}

void Map::showIslands() {
    if (!currentPosition_) {
        std::cout << "You are on water ! \n";
    } else {
        std::cout << "Your current position is: " << currentPosition_->getPosition().getPositionX() << " "
                  << currentPosition_->getPosition().getPositionY() << '\n';
    }
    std::cout << "Next other islands position: \n";
    for (const auto& element : allIslands) {
        std::cout << element.getPosition().getPositionX() << " " << element.getPosition().getPositionY() << '\n';
    }
}

void Map::travel(Island* island) {
    currentPosition_ = island;
}
