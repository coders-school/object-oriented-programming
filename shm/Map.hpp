#pragma once

#include "Island.hpp"
#include <vector>

class Map {
private:
    std::vector<Island&> islands_;
    Island* currentPosition_;
};