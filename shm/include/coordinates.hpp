#pragma once

class Coordinates {
public:
    Coordinates(int positionX, int positionY);
    bool operator==(const Coordinates& other);
    static size_t distance(const Coordinates& lhs, const Coordinates& rhs);

private:
    int positionX_;
    int positionY_;
};
