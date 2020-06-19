#pragma once

#include <string>

class Coordinates {
public:
    Coordinates(size_t posX, size_t posY);
    bool operator==(const Coordinates& pos) const {
        return positionX_ == pos.positionX_ && positionY_ == pos.positionY_;
    }
private:
    size_t positionX_;
    size_t positionY_;
};

class Island {
public:
    Island(size_t posX, size_t posY);
    Coordinates getPosition();
private:
    Coordinates position_;
};
