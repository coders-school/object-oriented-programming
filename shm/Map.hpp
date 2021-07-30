#ifndef SHIP_HPP
#define SHIP_HPP

#include <vector>
#include "Coordinates.hpp"
#include "Island.hpp"

// Class used to represent game map
class Map
{
private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(std::vector<Coordinates>, Coordinates);
    void fillMapWithIslands();

public:
    Map();
    void DebugPrintIsland();
    Island *getIsland(const Coordinates &coordinate);
    void addIsland(Coordinates &coordinate);
};
#endif