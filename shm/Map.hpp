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
    void PrintCurrentPosition();
    Island *getIsland(const Coordinates* );
    void addIsland(Coordinates);
    friend class Game;
    Island* getCurrentPos() {return current_pos_;}
    void changeCurrentPosition(Island* position) {current_pos_ = position;}
    size_t calculateDistance(Island);

private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(const std::vector<Coordinates>& vec, const Coordinates& c);
    void SetUpRandomIsland();
};
