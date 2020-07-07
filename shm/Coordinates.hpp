#pragma once

#include <ostream>

struct Coordinates
{
    Coordinates();
    Coordinates(int position_x_, int position_y_);

    int position_x;
    int position_y;

    friend bool operator==(const Coordinates& lhs, const Coordinates& rhs);
    friend bool operator!=(const Coordinates& lhs, const Coordinates& rhs);
};

bool operator==(const Coordinates& lhs, const Coordinates& rhs);
bool operator!=(const Coordinates& lhs, const Coordinates& rhs);
std::ostream& operator<<(std::ostream& os, const Coordinates& position);
