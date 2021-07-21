#pragma once
#include <vector>

class Map {
public:
    Map();
    Island* const getIsland(const Coordinates& coordinate);

private:
    Coordinates getRandomCoordinates();
    const int maxWidth_ = 99;
    const int maxHeight_ = 99;
    const int islandsQuantity_ = 10;
    std::vector<Island> islands_;
    Island* currentPostion_;
};