#include "map.hpp"
#include <functional>
#include <iostream>
#include <random>
#include <map>

map::map() {

    auto returnPaired = generateIslandPosition();
    std::vector<Island> vecofIslands{};
    vecofIslands.reserve(MAX_ISLANDS);
    for(int i =  0; i < MAX_ISLANDS; ++i) {
        vecofIslands.push_back(Coordinates(returnPaired[i].first,returnPaired[i].second));        
    }
    for(auto& a : vecofIslands) {
        map_.emplace_back(a);
    }
    // std::cout<<"In c'tor:\n";
    // for(int i = 0; i < MAX_ISLANDS; ++i) {
    //     std::cout<< map_[i].get().getPosition().getPositionX()<< ' ' << map_[i].get().getPosition().getPositionY() << '\n';
    // }

}   

void map::printIslands()const {
    for(auto& a : map_) {
        std::cout<<a.get().getPosition().getPositionX()<<' '<<a.get().getPosition().getPositionY()<<'\n';
    }
    
}
std::vector<std::pair<int,int>> map::generateIslandPosition() {
    std::map<int, int> vecOfPairs{};
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 106);
    while(vecOfPairs.size() < MAX_ISLANDS) {
        vecOfPairs[distrib(gen)] = distrib(gen);
    }
    std::vector<std::pair<int,int>> returnPair{};
    for(auto& a : vecOfPairs) {
        returnPair.push_back(std::make_pair(a.first,a.second));
    }
    return returnPair;
}
