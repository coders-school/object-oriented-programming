#include "Map.hpp"
#include <algorithm>
#include <random>
#include <cstddef>

Map::Map(){
    islandsLocations_.reserve(amountOfIslands);
    void generateIslands(int numIslandsToGenerate);
}

void Map::generateIslands(int numIslandsToGenerate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minPositionXY, maxPositionXY);
    
    do { 
        size_t positionX = distrib(gen); 
        size_t positionY = distrib(gen); 
        if (std::any_of(islandsLocations_.begin(), islandsLocations_.end(), 
                [positionX, positionY](auto& island) { 
                return island.getPosition() == Coordinates(positionX, positionY); 
            })) { 
            islandsLocations_.push_back(Island(positionX, positionY));
        } 
    } while (amountOfIslands <10); 
}

void Map::setCurrentPosition(Island* const currentPosition) {
    currentPosition_ = currentPosition;
}

void Map::addIsland(const Island& newIsland) {
    islandsLocations_.push_back(newIsland);
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto island = std::find_if(islandsLocations_.begin(), islandsLocations_.end(),
                               [&coordinate](const auto& isld) {
                                   return isld.Island::getPosition() == coordinate;
                               });

    return &(*island);
}

