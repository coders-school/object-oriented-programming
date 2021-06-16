#include "map.hpp"

coordinateType generatePosition() {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(0,10);

    return distrib(gen);
}

void addIslandsToMap(std::vector<Island> islandVec_, size_t number) {
    for (size_t i = 0, i < number, i++) {    
        do
        {
            auto posX = generatePosition();
            auto posY = generatePosition();
            Island newPosition(posX, posY);
   
            auto result = find_if(islandVec_.begin(), islandVec_.end(),
                        ()[const Island& position]{ return position.getPosition() == newPosition };                   
   
        } while (result != islandVec_.end());
        
        islandVec_.push_back(newPosition);
    }
}


Map::Map() {
    std::vector<Island> islandVec_;
    addIslandsToMap(islandVec_, 10);
}
   

std::vector<Island> Map::getIslandVec() const {
    return islandVec_;
}

Island* Map::getCurrentPosition() const{
    return currentPosition_;
}


