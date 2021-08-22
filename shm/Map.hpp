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
    Island *currentPos_;
    std::vector<std::unique_ptr<Island>> islands_;
    void fillMapWithIslands();
    

public:
    Map();
    Island* getIsland(const Coordinates &coordinate);
    Island* getIsland(const size_t index){return islands_[index - 1].get();};
    Coordinates generateCoordinates();
    Island* getCurrentIsland() { return currentPos_; };
    size_t getDistanceToIsland(Island* destination) const ;
    void setCurrentPos(Island* destination) {currentPos_ = destination;};
    friend std::ostream &operator<<(std::ostream &, const Map &map);

};
#endif