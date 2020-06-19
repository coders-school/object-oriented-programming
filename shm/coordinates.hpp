#pragma once

#include <string>

class Coordinates {
public:
    Coordinates(int32_t positionX, int32_t positionY);
    bool operator==(const Coordinates& position);
    int32_t getPositionX() const;
    int32_t getPositionY() const;

private:
    const int32_t positionX_;
    const int32_t positionY_;
};
