#pragma once

class Coordinates {
public:
    Coordinates(size_t posX, size_t posY)
        : posX{posX}, posY{posY} {}

    friend bool operator==(const Coordinates& lhs, const Coordinates& rhs);

private:
    const size_t posX;
    const size_t posY;
};