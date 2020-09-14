#include "constValues.hpp"
#include "coordinates.hpp"

#include <cmath>

Coordinates::Coordinates()
    : positionX_(constValues::defaultPositionX), positionY_(constValues::defaultPositionY) {}
   
Coordinates::Coordinates(int positionX, int positionY)
    : positionX_(positionX), positionY_(positionY) {}

int Coordinates::Distance(const Coordinates& pointA, 
                          const Coordinates& pointB) {
    return static_cast<int>(std::sqrt(std::pow((pointA.positionX_ - pointB.positionX_), 2) +
                                      std::pow((pointA.positionY_ - pointB.positionY_), 2)));
}

bool Coordinates::operator==(const Coordinates& currentPosition) const {
    return positionX_ == currentPosition.positionX_ && positionY_ == currentPosition.positionY_;
}

std::ostream& operator<<(std::ostream& print, const Coordinates& coords) {
    return print << "(X:" << coords.getPositionX() << ", Y:" << coords.getPositionY() << ")";
}
