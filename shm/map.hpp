#pragma once
#include <vector>
#include "coordinates.hpp"
#include "island.hpp"
class Map {
public:
    Map(std::shared_ptr<Time> time);
    Island* const getIsland(const Coordinates& coordinate);
    std::vector<Island> getEveryIsland() const;

protected:
    std::shared_ptr<Time> time_{};
    
private:
    Coordinates getRandomCoordinates();
    const int maxWidth_ = 99;
    const int maxHeight_ = 99;
    const int islandsQuantity_ = 10;
    std::vector<Island> islands_;
    Island* currentPostion_;
};