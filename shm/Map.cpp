#include "Map.hpp"
#include <algorithm>
#include <random>
#include <iostream>

Map::Map(){
    islandsLocations_.reserve(amountIslands);
    generateIslands();
}

void Map::generateIslands() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(widthIsland, heightIsland);
    
      for (size_t i = 0; i < amountIslands; i++) { 
        size_t positionX; 
        size_t positionY; 
        do { 
            size_t positionX = distrib(gen); 
            size_t positionY = distrib(gen);
        } while (std::any_of(islandsLocations_.begin(), islandsLocations_.end(), [positionX, positionY](auto& island) { 
            return island.getPosition() == Coordinates(positionX, positionY); 
        })); 
        islandsLocations_.push_back(Island(positionX, positionY)); 
    }
}

void Map::setCurrentPosition(Island* const currentPosition) {
    currentPosition_ = currentPosition;
}

void Map::addIsland(const Island& newIsland) {
    islandsLocations_.push_back(newIsland);
}
