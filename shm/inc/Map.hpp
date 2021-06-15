#pragma once

#include <vector>

#include "Island.hpp"

class Map {
public:

private:
    std::vector<Island&> vectorOfIslands_;
    Island* currentPosition_;
};
