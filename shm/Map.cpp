#include "map.hpp"

coordinateType generatePosition() {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(0,10);

    return distrib(gen);
}

void addRandomIsland(std::vector<Island>& vec, size_t number) {
    vec.reserve(number);
    for (size_t i = 0, i < number, i++) {    
        do
        {
            auto posX = generatePosition();
            auto posY = generatePosition();
            Island newIsland(posX, posY);
   
            auto check = find_if(vec.begin(), vec.end(),
                            [](const Island& island) { 
                                return island.getPosition() == newIsland;
                            };
   
        } while (check != vec.end());
        
        vec.push_back(newIsland);
    }
}


Map::Map() {
    addRandomIsland(islandVec_, 10);
}
   

std::vector<Island> Map::getIslandVec() const {
    return islandVec_;
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}

Island* Map::getIsland(const Island::Coordinates& coordinate) {
    for (auto& el : islandVec_) {
        if (el.getPosition().operator==(coordinate)) {
            return &el;
        }
    }
    return nullptr;
}
