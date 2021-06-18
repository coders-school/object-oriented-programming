#pragma once

#include "Island.hpp"
#include <vector>

#include <memory>
#include <vector>
class Map {
public:
    Map();

    //std::unique_ptr<Island> getIsland(const Island::Coordinates&);
    Island* getIsland(const Island::Coordinates&);

private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
