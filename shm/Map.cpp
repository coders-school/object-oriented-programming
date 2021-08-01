#include "Map.hpp"
#include <random>
#include <utility>
#include <algorithm>

constexpr size_t NUMBER_OF_ISLANDS = 10;
constexpr size_t MAP_SIZE = 100;

Map::Map()
{
    islands_.reserve(NUMBER_OF_ISLANDS);
    fillMapWithIslands();
    
}

void Map::fillMapWithIslands()
{
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::uniform_real_distribution<> distrib(0, MAP_SIZE);

    for (int i = 0; i < NUMBER_OF_ISLANDS; i++)
    {
        Coordinates coordinates(distrib(gen), 0);

        while (getIsland(coordinates) != nullptr)
        {
            coordinates.setPositionX(distrib(gen));
            coordinates.setPositionY(distrib(gen));
        }
        islands_.push_back(Island(coordinates));
    }
}

Island *Map::getIsland(const Coordinates &coordinates)
{
    auto itr = islands_.begin();
    itr = std::find(islands_.begin(), islands_.end(), coordinates);
    if (itr != islands_.end())
    {
        return &(*itr);
    }
    return nullptr;
}

void Map::addIsland(Coordinates &coordinate)
{
    islands_.push_back(Island(coordinate));
}