#pragma once

#include "coordinates.hpp"

class Island {
   public:
    Coordinates getPosition() const;

   private:
    Coordinates position_;
};
