#pragma once

#include <cstddef>

class Coordinates {
public:
    Coordinates(int positionX, int positionY)
        : positionX_(positionX), positionY_(positionY) {}

    bool operator==(const Coordinates& coordToCheck) const;

    static size_t distance(const Coordinates& lhs, const Coordinates& rhs);

private:
    int positionX_;
    int positionY_;
};
