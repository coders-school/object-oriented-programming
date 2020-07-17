#pragma once

#include <vector>

#include "Coordinates.hpp"
#include "Island.hpp"

class Map {
    std::vector<Island> islands_;
    Island* currentPosition_;

public:
    Map();
    Island* getCurrentPosition() const;
    Island* getIsland(const Coordinates&);
};