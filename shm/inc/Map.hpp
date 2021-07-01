#pragma once

#include "shm/inc/Island.hpp"

#include <vector>

//class responsible for manage cartography in game
class Map {
public:
    Map();
    Island* getIsland(const Island::Coordinates&);

private:
    std::vector<Island> vectorOfIslands_;
    Island* currentPosition_;
};
