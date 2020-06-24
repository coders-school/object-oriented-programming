#pragma once

#include <vector>

int constexpr DEFAULT_POSITION_X = 0;
int constexpr DEFAULT_POSITION_Y = 0;

class Coordinates {
public:
    Coordinates();
    Coordinates(int positionX, int positionY);

    bool operator==(const Coordinates& currentPosition) const;

    int getPositionX() const { return positionX_; }
    int getPositionY() const { return positionY_; }

private:
    const int positionX_;
    const int positionY_;
};
