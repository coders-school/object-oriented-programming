#pragma once
#include <cstddef>
#include <iostream>

class Coordinates {
public:
    Coordinates(int positionX, int positionY);
    bool operator==(const Coordinates& other);
    static size_t distance(const Coordinates& lhs, const Coordinates& rhs);
    friend std::ostream & operator<<(std::ostream & stream, const Coordinates& coords);

private:
    int positionX_;
    int positionY_;
};
