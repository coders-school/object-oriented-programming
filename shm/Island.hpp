#pragma once

struct Coordinates
{
    Coordinates() : x(0), y(0) {}
    Coordinates(int position_x_, int position_y_) : position_x(position_x_), position_y(position_y_) {}

    int position_x;
    int position_y;

    friend bool operator==(const Coordinates& lhs, const Coordinates& rhs);
    friend bool operator!=(const Coordinates& lhs, const Coordinates& rhs);
};

bool operator==(const Coordinates& lhs, const Coordinates& rhs)
{
    return lhs.x == rhs.x and lhs.y == rhs.y;
}

bool operator!=(const Coordinates& lhs, const Coordinates& rhs)
{
    return lhs.x != rhs.x or lhs.y != rhs.y;
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
