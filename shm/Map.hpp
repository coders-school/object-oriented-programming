#pragma once
#include <vector>
#include "island.hpp"
#include <random>
#include <algorithm>
#include <utility>
#include <iostream>

class Map
{
public:
    Map()
    {
        islands_.reserve(10);
        std::random_device rd;
        std::random_device rd2;
        std::mt19937 gen(rd());
        std::mt19937 gen2(rd2());
        std::uniform_real_distribution<> distrib(-100, 100);


        std::vector<Coordinates> cords;
        for (int i = 0; i < 10; i++)
        {
            Coordinates c(distrib(gen), distrib(gen2));
            // while (contains(cords, c))
            // {
            //     c.SetPositionX(distrib(gen)).SetPositionY(distrib(gen));
            // }
            islands_.push_back(Island (c));
        }

    }

    void DebugPrintIsland (){
        for (auto &el : islands_){
            std::cout << el.GetPosition().GetPositionX() << " | " << el.GetPosition().GetPositionY() << '\n';
        }
    }
/*
    tworzymym obiekt Coordinates
    sprawdzić czy taki obiekt istnieje w wektorze
    jeśli istnieje to generujemy kolejny
    jeśli nie to dodajemy
*/

private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(std::vector<Coordinates>, Coordinates);
};
