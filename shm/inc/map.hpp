#pragma once

#include <vector>

#include "island.hpp"

class Map {
public:
    Map();

    void travel(size_t option);

    size_t getDaysToArrive(size_t option);

    Island* getIsland(const Coordinates& coordinates);
    Island* getCurrentPosition() const { return currentPosition_; }

    friend std::ostream& operator<<(std::ostream& out, Map& map);

    static constexpr size_t kIslandAmt = 10;

private:
    void generateIslands();

    std::vector<Island> islands_;
    Island* currentPosition_;
};
