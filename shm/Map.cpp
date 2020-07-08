
#include <iostream>

#include "Map.hpp"
#include "ShmExceptions.hpp"

Map::Map() : mapXsize(defaultXsize), mapYsize(defaultYsize)
{
    randomIslandGenerator(defaultIslandsAmount);
}
Map::Map(int sizeY, int sizeX, int islandsAmount) : mapXsize(sizeY), mapYsize(sizeX)
{
    if (islandsAmount <= (sizeY * sizeX))
    {
        randomIslandGenerator(islandsAmount);
    }
    else
    {
        throw AmountException("Too many Islands!");
        Map();
    }
}

Island Map::getIsland(const Coordinates& corr)
{
    auto iter =
        std::find_if(std::begin(islands), std::end(islands), [corr](Island& is) { return is.getPosition() == corr; });
    if (iter == std::end(islands))
    {
        return Island{-1, -1};
    }
    else
    {
        return *iter;
    }
}

void Map::randomIslandGenerator(size_t amount)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::vector<int> map_(mapXsize * mapYsize);
    std::iota(std::begin(map_), std::end(map_), 0);
    std::shuffle(std::begin(map_), std::end(map_), gen);

    for (size_t i = 0; i < amount; i++)
    {
        islands.push_back(Island(map_[i] % mapXsize, ((map_[i]) / mapXsize) % mapYsize));
    }
}


