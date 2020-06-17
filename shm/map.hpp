
#pragma once
#include <vector>

#include "island.hpp"

class Map {
public:
    Map() {};
    ~Map() {};

private:
    std::vector<Island> islands;
    Island currentPosition_;
}