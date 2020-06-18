#pragma once

#include <vector>

#include "Island.hpp"

class Map {
private:
    std::vector<Island> vecOfIslands_;
    Island* currentPosition_;
};
