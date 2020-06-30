#pragma once

#include <ostream>

struct Coordinates
{
    Coordinates() : position_x(0), position_y(0) {}
    Coordinates(int position_x_, int position_y_) : position_x(position_x_), position_y(position_y_) {}

    int position_x;
    int position_y;

    friend bool operator==(const Coordinates& lhs, const Coordinates& rhs);
    friend bool operator!=(const Coordinates& lhs, const Coordinates& rhs);
};

bool operator==(const Coordinates& lhs, const Coordinates& rhs);
bool operator!=(const Coordinates& lhs, const Coordinates& rhs);
std::ostream& operator<<(std::ostream& os, const Coordinates& position);
