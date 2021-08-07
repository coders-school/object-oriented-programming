#include <algorithm>
#include <iostream>
#include <random>
#include <utility>

#include "coordinates.hpp"
#include "island.hpp"
#include "Map.hpp"

namespace constVariables{
    constexpr size_t COORDINATE_MIN = 0;
    constexpr size_t COORDINATE_MAX = 99;
    constexpr size_t ISLANDS_COUNT = 10;
}

Map::Map(Time * time) {
    SetUpRandomIsland(time);
}

void Map::SetUpRandomIsland(Time * time){
    islands_.reserve(constVariables::ISLANDS_COUNT);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(constVariables::COORDINATE_MIN , constVariables::COORDINATE_MAX);

    std::vector<Coordinates> cords;
    cords.reserve(constVariables::ISLANDS_COUNT);
    for (int i = 0; i < constVariables::ISLANDS_COUNT; i++)
    {   
        Coordinates c ((float)distrib(gen), (float)distrib(gen));

        while (contains(cords, c))
        {
            c.SetPositionX(distrib(gen));
            c.SetPositionY(distrib(gen));
        }
        islands_.push_back(Island (c, time));
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
    auto selectedIsland = std::find_if(islands_.begin(), islands_.end(), [&coordinate](Island& i) { return i.getPosition() == coordinate; });
    if(selectedIsland != islands_.end())
    {
        return &(*selectedIsland);
    }
    return nullptr;
}

void Map::addIsland(Coordinates &coordinate, Time * time)
{
    islands_.push_back(Island(coordinate, time));
}
