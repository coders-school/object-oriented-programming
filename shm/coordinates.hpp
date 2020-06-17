#pragma once

#include <string>

class Coordinates {
   public:
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

   private:
    int positionX_;
    int positionY_;
};
