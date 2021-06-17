#include "Map.hpp"
#include <algorithm>

coordinateType generatePosition() {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(0,10);

    return distrib(gen);
}

void fillWithRandomIslands(std::vector<Island>& vec, size_t number) {
    // Consider making it method in Island class
    for (size_t i = 0; i < number; i++) {
        // while (true) used as a walkaround
        while (true)
        {
            auto posX = generatePosition();
            auto posY = generatePosition();
            Island newIsland(posX, posY);
   
            auto check = std::find_if(vec.begin(), vec.end(),
                    [ &newIsland ]( const Island& island ) { 
                        return island.getPosition() == newIsland.getPosition();
                    });

            if(check == vec.end()) {
                vec.push_back(newIsland);
                break;
            }
        }
    }
}

Map::Map() {
    islandVec_.reserve(defaultIslandsNumber);
    fillWithRandomIslands(islandVec_, defaultIslandsNumber);
} 

std::vector<Island> Map::getIslandVec() const {
    return islandVec_;
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}

Island* Map::getIsland(const Island::Coordinates& coordinate) {
    for (auto& el : islandVec_) {
        if (el.getPosition() == coordinate) {
            return &el;
        }
    }
    return nullptr;
}
