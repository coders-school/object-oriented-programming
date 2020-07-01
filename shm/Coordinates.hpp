#pragma once

#include <iostream>

class Coordinates {
public:
    Coordinates(const int positionX, const int positionY);

    bool operator==(const Coordinates& coordinatesToCheck) const;
    bool operator!=(const Coordinates& coordinatesToCheck) const;

    friend std::ostream& operator<<(std::ostream& out, const Coordinates& coord);

private:
    const int _positionX;
    const int _positionY;
};

std::ostream& operator<<(std::ostream& out, const Coordinates& coord);
