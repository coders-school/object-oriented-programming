#pragma once
#include "island.hpp"
#include <vector>
#include "Time.hpp"

//class Island;
class Coordinates;

//Class responsible for representing map in game
class Map {
public:
    Map(Time * time);
    void DebugPrintIsland();
    void PrintCurrentPosition();
    friend class Game;
    Island* getCurrentPos() {return current_pos_;}
    void changeCurrentPosition(Island* position) {current_pos_ = position;}
    size_t calculateDistance(Island);
    Island *getIsland(const Coordinates &);
    void addIsland(Coordinates &, Time *);

private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(const std::vector<Coordinates>&, const Coordinates&);
    void SetUpRandomIsland(Time *);
};
