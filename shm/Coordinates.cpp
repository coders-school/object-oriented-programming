#include <ostream>

#include "Coordinates.hpp"

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
