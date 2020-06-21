#pragma once
#include <cmath>
#include <iostream>

class Coordinates {
public:
	Coordinates();
	Coordinates(size_t pos_x, size_t pos_y)
	static size_t Distance(const Coordinates& lhs, const Coordinates& rhs);
	bool operator==(const Coordinates& lhs) const;

private:
	const size_t pos_x_{ 0 };
	const size_t pos_y_{ 0 };
};