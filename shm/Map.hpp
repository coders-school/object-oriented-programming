#pragma once
#include "island.hpp"
#include <vector>

//class Island;
class Coordinates;

//Class responsible for representing map in game
class Map {
public:
    Map();
    void DebugPrintIsland();
    Island *getIsland(const Coordinates);
    void addIsland(Coordinates);
    friend class Game;

private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(const std::vector<Coordinates>& vec, const Coordinates& c);
    void SetUpRandomIsland();
};
