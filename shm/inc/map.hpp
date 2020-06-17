#pragma once

#include <vector>

#include "island.hpp"

class Map {
private:
    std::vector<Island> islands_;
    Island* currentPosition_;
};
