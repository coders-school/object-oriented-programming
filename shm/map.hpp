#pragma once

#include <vector>

// Forward declaration, include Island class once it's ready
class Island;
class Map {
    std::vector<Island> islandVec_;
    Island* currentPosition_;

public:
    std::vector<Island> getIslandVec() const;
    Island* getCurrentPosition() const;
}