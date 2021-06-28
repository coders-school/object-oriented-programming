#ifndef ISLAND_HPP
#define ISLAND_HPP
#include "Coordinates.hpp";

class Island {
private:
    Coordinates position_;

public:
    Island(Coordinates coordinates);
    Coordinates getPosition_() const {return position_;};
};

#endif