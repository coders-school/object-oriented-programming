#include <ostream>

#include "Coordinates.hpp"

Coordinates::Coordinates(int position_x_, int position_y_) : position_x(position_x_), position_y(position_y_)
{
}
Coordinates::Coordinates() : position_x(0), position_y(0)
{
}

std::ostream& operator<<(std::ostream& os, const Coordinates& position)
{
    os << " x: " << position.position_x << " y: " << position.position_y;
    return os;
}

bool operator==(const Coordinates& lhs, const Coordinates& rhs)
{
    return lhs.position_x == rhs.position_x and lhs.position_y == rhs.position_y;
}

bool operator!=(const Coordinates& lhs, const Coordinates& rhs)
{
    return lhs.position_x != rhs.position_x or lhs.position_y != rhs.position_y;
}
