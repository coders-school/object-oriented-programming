#pragma once

#include <vector>

#include "Island.hpp"

class Map {
    std::vector<Island> islands_;
    Island* currentPosition_;

public:
    Map();
    Island* getIsland(const Coordinates&);
    Island* getCurrentPosition() const;
    uint16_t getDistanceToIsland(Island*) const;
    void Travel(Island*);
    friend std::ostream& operator<<(std::ostream&, const Map&);
};