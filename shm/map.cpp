#include "map.hpp"
#include <map>
#include <random>
#include <string>

Map::Map() {

    constexpr int numOfIslands = 10;
    allIslands.reserve(numOfIslands);

    std::map<std::string, int> repsChecker;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(MAP_RND_DISTRIBUTION_MIN, MAP_RND_DISTRIBUTION_MAX);

    bool coordinateExist = false;
    int posX = 0;
    int posY = 0;
    std::string coordinateXY = "";

    for (std::size_t i = 0; i < numOfIslands; ++i) {

        do {
            posX = distrib(gen);
            posY = distrib(gen);

            coordinateXY = std::string(std::to_string(posX) + std::to_string(posY));
            auto tryInsert = repsChecker.emplace(coordinateXY, 0);
            coordinateExist = tryInsert.second;

        } while (!coordinateExist);

        allIslands.emplace_back(Island(posX, posY));
    }
}


Island* Map::getIsland(const Coordinates& coordinate)
{
    for (Island& island : allIslands){
        if (island.getPosition() == coordinate){
            return &island;
        }
    }
    return nullptr;
}
