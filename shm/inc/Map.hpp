#pragma once

#include "shm/inc/Island.hpp"

#include <memory>
#include <vector>
class Map {
public:
    Map();
    std::unique_ptr<Island> getIsland(const Island::Coordinates&);

    Island* getIsland(const Island::Coordinates&);

private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
