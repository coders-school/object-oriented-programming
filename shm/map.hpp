#pragma once

#include <vector>

#include "island.hpp"

class Map {
private:
    std::vector<Island> vecOfIslandOnMap_;
    Island* currentPosition_;

public:
    Map();
};