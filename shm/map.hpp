#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>

class Map {
public:
    Map() = default;
    Map(Island* currentPosition) //I dont know, if i want to fill vector of islands, i need to put island into constructor, or filling the vector will be done only by function
        : currentPostion_(currentPosition)
        {}
    void initializeMap(Island& island);
    Island* const getPosition();
    Island* getIsland(const Island::Coordinates& coordinate);
private:
    std::vector<Island&> islands_; //I dont know if this vector is going to be the only place where we are collecting islands. If its the only way to somehow "remember" islands, then pointer is pointless (hehe) 
    Island* currentPostion_;
};
