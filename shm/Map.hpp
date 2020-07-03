#pragma once

#include <vector>

#include "Island.hpp"

class Map {
public:
    Map();
    Island* getIsland(const Coordinates& coordinate);
    Island* getCurrentIsland() const { return _currentIsland; }

private:
    std::vector<Island> _vecOfIslands;
    Island* _currentIsland;
};
