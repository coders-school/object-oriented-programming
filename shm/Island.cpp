#include "Island.hpp"
#include "Coordinates.hpp"

Island::Island() : position_(Coordinates(0, 0)) {}
Island::Island(int x, int y) : position_(Coordinates(x, y)) {}

std::ostream& operator<<(std::ostream& os, Island& island)
{
    os << "Island: position " << island.getPosition();
    return os;
}

bool operator==(Island& lhs, Island& rhs)
{
    return lhs.getPosition() == rhs.getPosition();
}
