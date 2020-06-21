#pragma once

#include <vector>

class Coordinates {
public:
    Coordinates();
    Coordinates(const int positionX, const int positionY);

    bool operator==(const Coordinates& currentPosition);

    int getPositionX() const { return positionX_; }
    int getPositionY() const { return positionY_; }

private:
    const int positionX_;
    const int positionY_;
};
