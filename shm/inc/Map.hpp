#pragma once

#include "shm/inc/Island.hpp"

#include <vector>

constexpr size_t COORDINATE_MIN = 0;
constexpr size_t COORDINATE_MAX = 99;
constexpr size_t ISLANDS_COUNT = 10;

class Map {
public:
    Map();
    Island* getIsland(const Island::Coordinates&);
    std::vector<Island> getIslands() { return islands_; }
    Island* getCurrentPosition() const;
    void setCurrentPosition(Island* island);
    
private:
    std::vector<Island> islands_;
    Island* currentPosition_;
};
