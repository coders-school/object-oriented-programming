#pragma once

#include <string>

class Coordinates {
public:
    Coordinates(size_t, size_t);
    bool operator==(const Coordinates& pos) const {
        return positionX == pos.positionX && positionY == pos.positionY;
    }
private:
    size_t positionX;
    size_t positionY;
};

class Island {
public:
    Island(size_t, size_t);
    Coordinates getPosition();
private:
    Coordinates position_;
};
