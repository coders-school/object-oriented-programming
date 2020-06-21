#pragma once

#include <cstddef>

class Coordinates {
private:
    size_t positionX_ {0};
    size_t positionY_ {0};

public:
    Coordinates(size_t positionX, size_t positionY) : positionX_(positionX), positionY_(positionY) {};
    bool operator==(const Coordinates& cord);
};
