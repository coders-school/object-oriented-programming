#pragma once

#include "coordinates.hpp"

class Island {
   public:
    Island(int positionX, int positionY);
    Coordinates getPosition() const;

   private:
    Coordinates position_;
};
