#include "coordinates.hpp"

Coordinates::Coordinates()
    : positionX_(0), positionY_(0) {}
    
Coordinates::Coordinates(const int positionX, const int positionY)
    : positionX_(positionX), positionY_(positionY) {}

Coordinates& Coordinates::operator==(std::vector<int> currentPosition) {
        currentPosition == position_;
        return *this;
    }
