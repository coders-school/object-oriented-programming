#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>

class Map {
public:
    Map();
    Island* const getPosition();
    Island* getIsland(const Island::Coordinates& coordinate);
private:
    const int maxWidth_ = 99;
    const int maxHeight_ = 99;
    const int islandsQuantity_ = 10;
    std::vector<Island> islands_;
    Island* currentPostion_;
};
