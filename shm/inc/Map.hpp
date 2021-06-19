#pragma once

#include "shm/inc/Island.hpp"

#include <vector>
#include <memory>


class Map {
public:
    Map();

private:
    std::vector<Island> vectorOfIslands_;
    std::unique_ptr<Island> currentPosition_;
};
