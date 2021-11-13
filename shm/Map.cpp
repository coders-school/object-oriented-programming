#include <algorithm>
#include <iostream>
#include <random>
#include <utility>
#include <iterator>
#include <math.h>
#include "coordinates.hpp"
#include "island.hpp"
#include "Map.hpp"

namespace constVariables
{

    constexpr size_t COORDINATE_MIN = 0;
    constexpr size_t COORDINATE_MAX = 99;
    constexpr size_t ISLANDS_COUNT = 10;

} // namespace constVariables

Map::Map(Time *time)
{
    SetUpRandomIsland(time);
}

void Map::SetUpRandomIsland(Time *time)
{
    // islands_.reserve(constVariables::ISLANDS_COUNT);
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_real_distribution<> distrib(constVariables::COORDINATE_MIN, constVariables::COORDINATE_MAX);
    // std::vector<Coordinates> cords;
    // cords.reserve(constVariables::ISLANDS_COUNT);
    // for (int i = 0; i < (int)constVariables::ISLANDS_COUNT; i++)
    // {
    //     int x = (int)distrib(gen);
    //     int y = (int)distrib(gen);
    //     Coordinates c(x, y);
    //     while (contains(cords, c))
    //     {
    //         x = (int)distrib(gen);
    //         y = (int)distrib(gen);
    //         c.SetPositionX(x);
    //         c.SetPositionY(y);
    //     }

    //     islands_.push_back(Island(c, time));
    //     cords.push_back(c);
    // }
    Coordinates cordy = Coordinates(10, 10);
    Island kwik = Island(cordy, time);
    islands_.push_back(kwik);
}

void Map::DebugPrintIsland()
{
    int j = 0;
    for (auto &el : islands_)
    {
        std::cout << j << " | " << std::to_string(el.getPosition().GetPositionX()) << " | " << std::to_string(el.getPosition().GetPositionY()) << '\n';

        j++;
    }
}

void Map::PrintCurrentPosition()
{
    std::cout << "Current coordinates: " << std::to_string(current_pos_->getPosition().GetPositionX()) << " | " << std::to_string(current_pos_->getPosition().GetPositionY()) << '\n';
}

bool Map::contains(const std::vector<Coordinates> &vec, const Coordinates &c)
{
    return std::find(vec.begin(), vec.end(), c) != vec.end();
}

size_t Map::calculateDistance(Island island_pos_)
{
    const auto distanceX = current_pos_->getPosition().GetPositionX();
    const auto distanceY = current_pos_->getPosition().GetPositionY();
    const auto disX = island_pos_.getPosition().GetPositionX();
    const auto disY = island_pos_.getPosition().GetPositionY();
    const auto distance = sqrt(pow((disX - distanceX), 2) + pow((disY - distanceY), 2));
    std::cout << "Distance: " << distance << '\n';
    return (size_t)distance;
}

void Map::addIsland(Coordinates &coordinate, Time *time)
{
    islands_.push_back(Island(coordinate, time));
}
