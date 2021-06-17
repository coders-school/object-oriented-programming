#include "map.hpp"

coordinateType generatePosition() {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(0,10);

    return distrib(gen);
}

void fillWithRandomIslands(std::vector<Island>& vec, size_t number) {
    for (size_t i = 0, i < number, i++) {    
        do
        {
            auto posX = generatePosition();
            auto posY = generatePosition();
            Island newIsland(posX, posY);
   
            auto check = find_if(vec.begin(), vec.end(),
                    [ &newIsland ]( const Island& island ) { 
                        return island.getPosition() == newIsland.getPosition();
                    });
        } while (check != vec.end());
        
        vec.push_back(newIsland);
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
