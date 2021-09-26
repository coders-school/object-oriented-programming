#pragma once
#include <vector>
#include "coordinates.hpp"
#include "island.hpp"
class Map {
public:
    Map() = default;
    Map(std::shared_ptr<Time> time);
    Island* const getIsland(const Coordinates& coordinate);
    std::vector<Island> getEveryIsland() const;
    std::vector<Island> islands_;
    
private:
    Coordinates getRandomCoordinates();
    const int maxWidth_ = 99;
    const int maxHeight_ = 99;
    const int islandsQuantity_ = 10;
    Island* currentPostion_;
};
