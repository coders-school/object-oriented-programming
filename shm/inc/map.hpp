#pragma once

#include <vector>

#include "Coordinates.hpp"
#include "Island.hpp"

class Map {
    std::vector<Island> islands_;
    Island* currentPosition_;

public:
    Map();
    Island* getIsland(const Island::Coordinates&);
    void creaIsland(size_t);
};
