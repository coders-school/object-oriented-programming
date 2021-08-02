#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include "Coordinates.hpp"
#include "Island.hpp"
#include <memory>

// Class used to represent game map
class Map
{
private:
    Island *current_pos_;
    std::vector<std::unique_ptr<Island>> islands_;
    void fillMapWithIslands();
    

public:
    Map();
    Island *getIsland(const Coordinates &coordinate);
    Coordinates generateCoordinates();
};
#endif