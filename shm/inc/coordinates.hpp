#pragma once

#include <string>

class Coordinates {
public:
    Coordinates() = default;
    Coordinates(size_t positionX, size_t positionY);

    bool operator==(const Coordinates& position) const;

    size_t getPositionX() const;
    size_t getPositionY() const;

private:
    const size_t positionX_;
    const size_t positionY_;
};
