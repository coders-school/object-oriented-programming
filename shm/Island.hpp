#ifndef ISLAND_HPP
#define ISLAND_HPP
#include "Coordinates.hpp"

// Class used to represent island on the game map
class Island
{
private:
    Coordinates position_;

public:
    explicit Island(Coordinates coordinates);
    Coordinates getPosition() const { return position_; };
};

#endif