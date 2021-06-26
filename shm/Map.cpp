#include "Map.hpp"

bool Map::contains(std::vector<Coordinates> vec, Coordinates c)
{
    if (std::find(vec.begin(), vec.end(), c) != vec.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}