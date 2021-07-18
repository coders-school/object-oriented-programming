#pragma once
#include "coordinates.hpp"

class Island {    
public:
    Island() {}

    Island(Coordinates position)
    : position_(position)
    {}

    Coordinates getPosition() const;
    void setPosition(Coordinates );
    

private:
    Coordinates position_;
};