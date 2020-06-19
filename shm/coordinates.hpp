#pragma once

#include <string>

class Coordinates {
public:
    Coordinates(int32_t positionX, int32_t positionY);
    bool operator==(const Coordinates& position);

private:
    const int positionX_;
    const int positionY_;
};
