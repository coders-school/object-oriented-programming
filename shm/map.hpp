#pragma once

#include <vector>

#include "island.hpp"

class Map {
public:
    Map();

private:
    std::vector<Island> Islands_;
    Island* currentPosition_;
};
