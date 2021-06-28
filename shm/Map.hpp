#ifndef SHIP_HPP
#define SHIP_HPP
#include <vector>
#include "Island.hpp"
#include <random>
#include <algorithm>
#include <utility>
#include <iostream>
#include "Coordinates.hpp"

constexpr size_t NUMBER_OF_ISLANDS = 10;
constexpr size_t MAP_SIZE = 100;


class Map
{

private:
    Island* current_pos_;
    std::vector<Island> islands_;
    bool contains(std::vector<Coordinates>, Coordinates);

public:
    Map();
    void DebugPrintIsland();
    Island *getIsland(const Coordinates &coordinate);
    void addIsland(Coordinates &coordinate);
};
#endif