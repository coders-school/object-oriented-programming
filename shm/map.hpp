#pragma once
#include <vector>
#include <memory>
#include "island.hpp"

#define MAX_ISLANDS 10
class map {
public:
    map();
    void printIslands() const;
    Island* getIsland( const Coordinates&)const;

private:
    std::vector<std::pair<int, int>> generateIslandPosition();
    std::vector<std::shared_ptr<Island>> map_;
    Island* currentPosition_{};
};
