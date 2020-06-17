#pragma once

#include <string>

class Coordinates {
   public:
    Coordinates(int positionX, int positionY) : positionX_(positionX), positionY_(positionY) {}
    bool operator==(Coordinates& position);

   private:
    int positionX_;
    int positionY_;
};
