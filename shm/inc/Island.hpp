#pragma once

#include "Coordinates.hpp"

class Island {
public:
    Island(size_t x, size_t y);

    Coordinates getPosition() const;
    
private:
    Coordinates position_;
};
