#pragma once

#include <ostream>
#include <vector>
#include <iostream>

#include "Island.hpp"

constexpr size_t amountOfIslands = 10;
constexpr size_t minPositionXY = 1;
constexpr size_t maxPositionXY = 10;

class Map {
private:
    void generateIslands(int numOfIslandsToGenerate);
    Island* currentPosition_{nullptr};
    std::vector<Island> islandsLocations_;
    friend void populateMapScreen(std::ostream& out, const Map& map);

public:
    Map();
    void setCurrentPosition(Island* const currentPosition);
    void addIsland(const Island& newIsland);
    Island* getIsland(const Coordinates& coordinate);
    friend std::ostream& operator<<(std::ostream& out, const Map& map);
    size_t getDistanceToIsland(Island* destination);

    Island* getFirstIsland(){return &islandsLocations_[0];} //TEMPORARY
    void printIsland(){
        for (const auto& el : islandsLocations_) {
            std::cout<<"island in vec {X;Y} = { "<<el.getPosition().getX()<<" ; "<< el.getPosition().getY()<<" }\n";
        }
    }
};
