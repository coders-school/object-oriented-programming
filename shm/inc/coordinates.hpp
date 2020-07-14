#pragma once

#include <cstddef>
#include <iostream>

class Coordinates {
public:
    Coordinates(int positionX, int positionY)
        : positionX_(positionX), positionY_(positionY) {}

    bool operator==(const Coordinates& coordToCheck) const;
    bool operator!=(const Coordinates& coordToCheck) const;

    static size_t distance(const Coordinates& lhs, const Coordinates& rhs);

    friend std::ostream& operator<<(std::ostream& out, const Coordinates& cord);
private:
    int positionX_;
    int positionY_;
};
