#pragma once

#include <vector>

#include "Coordinates.hpp"
#include "Island.hpp"


constexpr size_t numOfIslands = 10;
constexpr size_t mapX = 100;
constexpr size_t mapY = 100;




class Map {
    std::vector<Island> islands_;
    Island* currentPosition_;

public:
    Map();
    
    Island* getIsland(const Island::Coordinates& coordinates);
    void creaIsland(size_t numb);
};