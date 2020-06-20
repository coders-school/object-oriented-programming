#pragma once

class Coordinates {
public:
    Coordinates(const int positionX, const int positionY);

    bool operator==(const Coordinates& coordinatesToCheck) const;
    bool operator!=(const Coordinates& coordinatesToCheck) const;

private:
    const int _positionX;
    const int _positionY;
};
