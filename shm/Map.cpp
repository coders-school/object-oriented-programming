
#include "Map.hpp"

void Map::randomIslandGenerator(size_t amount)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::vector<int> map_(mapXsize * mapYsize);
    std::iota(std::begin(map_), std::end(map_), 0);
    std::shuffle(std::begin(map_), std::end(map_), gen);

    for (size_t i = 0; i < amount; i++)
        islands.push_back(Island(map_[i] % mapXsize, ((map_[i]) / mapXsize) % mapYsize));
}


Island Map::getIsland(const Coordinates& corr)
{
    return *(std::find_if(
        std::begin(islands), std::end(islands), [corr](Island& is) { return is.getPosition() == corr; }));
}

