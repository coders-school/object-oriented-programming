#pragma once

#include <string>

class Coordinates {
   public:
    Coordinates(int positionX, int positionY);
    bool operator==(Coordinates& position);

   private:
    const int positionX_;
    const int positionY_;
};
