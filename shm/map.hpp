#pragma once
//uncomment when ready
//#include "island.hpp"
//#include "coordinates.hpp"
#include <vector>

///-------------------------------------------------
#warning remove this code when ilsands is ready


constexpr int MAP_RND_DISTRIBUTION_MIN = 1000;
constexpr int MAP_RND_DISTRIBUTION_MAX = 1010;

class Coordinates{
private:
    int x_;
    int y_; 
public:
    Coordinates(int x, int y): x_(x), y_(y){};
    bool operator==(const Coordinates &pos) {return ((x_== pos.x_) && (y_ == pos.y_));} 
};

class Island {
private:
    Coordinates position_;
    
public:
    Island(int x, int y): position_(Coordinates(x,y)){};
    inline Coordinates getPosition(){ return position_;}

};
///-------------------------------------------------


class Map {

public:

    Map();

    Island* getIsland(const Coordinates& coordinate);

private:

    std::vector<Island> allIslands;
    Island* currentPosition_;
};
