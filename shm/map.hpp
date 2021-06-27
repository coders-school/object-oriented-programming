#pragma once
#include "island.hpp"
#include <vector>

#define MAX_ISLANDS 10
class map {
public:
    map();
    void printIslands()const;
    std::vector<std::pair<int,int>> generateIslandPosition();
private:
  std::vector<std::reference_wrapper<Island>> map_{};
  Island *currentPosition_{};
};

