#pragma once

#include <iostream>

class Coordinates {
    uint16_t positionX_;
    uint16_t positionY_;

public:
    Coordinates() = default;
    Coordinates(uint16_t, uint16_t);
    bool operator==(const Coordinates&) const;
    uint16_t getPositionX() const;
    uint16_t getPositionY() const;
};