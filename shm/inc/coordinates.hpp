#pragma once

class Coordinates {
public:
    Coordinates(int positionX, int positionY)
        : positionX_(positionX), positionY_(positionY) {}

    bool operator==(const Coordinates& coordToCheck) const;

private:
    int positionX_;
    int positionY_;
};
