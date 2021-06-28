#include "Map.hpp"

Map::Map()
{
    islands_.reserve(ISLANDS_COUNT);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(COORDINATE_MIN, COORDINATE_MAX);

    std::vector<Coordinates> cords;
    
    for (int i = 0; i < ISLANDS_COUNT; i++)
    {
        Coordinates c;
        c.SetPositionX(distrib(gen));
        c.SetPositionY(distrib(gen));

        while (contains(cords, c))
        {
            c.SetPositionX(distrib(gen));
            c.SetPositionY(distrib(gen));
        }
        islands_.push_back(Island(c));
    }
}

void Map::DebugPrintIsland()
{
    for (auto &el : islands_)
    {
        std::cout << el.getPosition().GetPositionX() << " | " << el.getPosition().GetPositionY() << '\n';
    }
}

bool Map::contains(std::vector<Coordinates> vec, Coordinates c)
{
    if (std::find(vec.begin(), vec.end(), c) != vec.end())
    {
        return true;
    }
    return false;
}

Island *Map::getIsland(const Coordinates &coordinate)
{
    for (int i = 0; i < islands_.size(); i++)
    {
        if (islands_[i].getPosition() == coordinate)
        {
            return &islands_[i];
        }
    }
    return nullptr;
}

void Map::addIsland(Coordinates &coordinate)
{
    islands_.push_back(Island(coordinate));
}
