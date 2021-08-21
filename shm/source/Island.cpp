#include "Island.hpp"

Island::Coordinates::Coordinates(const int x, const int y):
	positionX(x),
	positionY(y)
{}

bool Island::Coordinates::operator==(const Coordinates& coordinates) {
	return (positionX == coordinates.positionX && positionY == coordinates.positionY);
}

Island::Island(const Coordinates& coordinates):
	position_(coordinates)
{}

Island::Coordinates Island::getPosition() const { 
	return position_; 
}
