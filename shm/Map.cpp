#include "Map.hpp"
#include <algorithm>
#include <random>
#include <cstddef>

Map::Map(){
    islandsLocations_.reserve(amountOfIslands);
    generateIslands(amountOfIslands);
}

void Map::generateIslands(int numOfIslandsToGenerate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minPositionXY, maxPositionXY);
    
    size_t positionX {}; 
    size_t positionY {};
    do { 
        positionX = distrib(gen); 
        positionY = distrib(gen); 
        if (std::any_of(islandsLocations_.begin(), islandsLocations_.end(), 
                [positionX, positionY](const auto& island) { 
                return island.getPosition() == Coordinates(positionX, positionY); 
            })) { 
            addIsland({positionX, positionY});
        } 
    } while (--numOfIslandsToGenerate); 
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

    return (island != islandsLocations_.end()) ? &(*island) : nullptr;
}
