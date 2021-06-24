#pragma once

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