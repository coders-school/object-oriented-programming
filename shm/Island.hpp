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

std::ostream& operator<<(std::ostream& os, const Coordinates& position)
{
    os << " x: " << position.position_x << " y: " << position.position_y;
    return os;
}

bool operator==(const Coordinates& lhs, const Coordinates& rhs)
{
    return lhs.position_x == rhs.position_x and lhs.position_y == rhs.position_y;
}

class Island
{
public:
    Island() : position_(Coordinates(0, 0)) {}
    Island(int x, int y) : position_(Coordinates(x, y)) {}

    Coordinates getPosition() { return position_; }

private:
    Coordinates position_;
};

std::ostream& operator<<(std::ostream& os, Island& island)
{
    os << "Island: position " << island.getPosition();
}
