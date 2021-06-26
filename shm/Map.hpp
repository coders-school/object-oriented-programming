#pragma once
#include <vector>
#include "island.hpp"
#include <random>
#include <algorithm>

class Map
{
public:
    Map()
    {
        islands_.reserve(10);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> distrib(-100, 100);

        std::vector<Coordinates> cords;
        for (int i = 0; i < 10; i++)
        {
            Coordinates c(distrib(gen), distrib(gen));
            while (contains(cords, c))
            {
                c.SetPositionX(distrib(gen)).SetPositionY(distrib(gen));
            }
            islands_.push_back(c);
        }
    }

private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(std::vector<Coordinates>, Coordinates);
};
