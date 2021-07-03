#include <algorithm>
#include <iostream>
#include <random>
#include <utility>

#include "coordinates.hpp"
#include "island.hpp"
#include "Map.hpp"

Map::Map() {
    SetUpRandomIsland();
}

void Map::SetUpRandomIsland(){
    islands_.reserve(ISLANDS_COUNT);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(COORDINATE_MIN , COORDINATE_MAX);

    std::vector<Coordinates> cords;
    cords.reserve(ISLANDS_COUNT);
    for (int i = 0; i < ISLANDS_COUNT; i++)
    {   
        Coordinates c ((float)distrib(gen), (float)distrib(gen));

        while (contains(cords, c))
        {
            c.SetPositionX(distrib(gen));
            c.SetPositionY(distrib(gen));
        }
        islands_.push_back(Island (c));
        cords.push_back(c);
    } 
}

void Map::DebugPrintIsland () {
    for (auto &el : islands_) {
        std::cout << std::to_string(el.getPosition().GetPositionX()) << " | " << std::to_string(el.getPosition().GetPositionY()) << '\n';
    }
}

bool Map::contains(const std::vector<Coordinates>& vec, const Coordinates& c) {
    return std::find(vec.begin(), vec.end(), c) != vec.end();
}

Island* Map::getIsland(const Coordinates& coordinate){
    // Find way to make find_if works: return std::find_if(islands_.begin(), islands_.end(), [&coordinate](Island i) { return i.getPosition() == coordinate; });
    for(int i = 0; i < islands_.size(); i++){
        if(islands_[i].getPosition() == coordinate){
            return &islands_[i];
        }
    }
    return nullptr;
}

void Map::addIsland(Coordinates& coordinate){
    islands_.push_back(Island (coordinate));
}