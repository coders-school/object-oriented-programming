#pragma once

#include "Island.hpp"
#include <vector>

class Map {
public:
    Map();

private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
