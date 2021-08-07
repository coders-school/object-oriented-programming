#pragma once
#include <vector>
#include "Time.hpp"

class Island;
class Coordinates;

//Class responsible for representing map in game
class Map {
public:
    Map(Time * time);
    void DebugPrintIsland();
    Island *getIsland(const Coordinates &coordinate);
    void addIsland(Coordinates &coordinate, Time * time);

private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(const std::vector<Coordinates>& vec, const Coordinates& c);
    void SetUpRandomIsland(Time *);
};
