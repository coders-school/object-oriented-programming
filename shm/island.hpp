#pragma once

#include <string>
#include "coordinates.hpp"

class Island {
   public:
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

   private:
    Coordinates position_;
};
