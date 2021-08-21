#pragma once

struct Island {
	struct Coordinates {
		int positionX;
		int positionY;

		Coordinates(const int x, const int y);

		bool operator==(const Coordinates& coordinates);
	};

	Island(const Coordinates& coordinates);

	Coordinates getPosition() const;

private:
	Coordinates position_;
};