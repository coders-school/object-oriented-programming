#pragma once

#include <vector>
#include "Island.hpp"
class Map {
    std::vector<Island> islandVec_;
    Island* currentPosition_;

public:
    std::vector<Island> getIslandVec() const;
    Island* getCurrentPosition() const;
};