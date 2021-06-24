#pragma once

#include "Coordinates.hpp"

struct Island {
	struct Coordinates {
		int positionX;
		int positionY;

		Coordinates(const int x, const int y):
			positionX(x),
			positionY(y)
		{}

		bool operator==(const Coordinates& coordinates) {
			return (positionX == coordinates.positionX && positionY == coordinates.positionY);
		}
	};

public:
	Island(const Coordinates& coordinates):
		position_(coordinates)
	{}

	Coordinates getPosition() const { return position_; }

private:
	Coordinates position_;

};