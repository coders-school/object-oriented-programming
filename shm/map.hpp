#pragma once

#include "island.hpp"

#include <vector>

class Map {
private:
    std::vector<Island> Islands_;
    Island* currentPosition_;
};
