#pragma once

#include <iostream>

class Coordinates {
    size_t positionX_;
    size_t positionY_;

public:
    Coordinates() = default;
    Coordinates(size_t, size_t);
    bool operator==(const Coordinates&) const;
    size_t getPositionX() const;
    size_t getPositionY() const;
};