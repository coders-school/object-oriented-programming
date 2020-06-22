#pragma once

#include <string>

class Coordinates {
public:
    Coordinates();
    Coordinates(size_t positionX, size_t positionY);

    bool operator==(const Coordinates& position) const;

    void setPosition(size_t positionX, size_t positionY);
    size_t getPositionX() const;
    size_t getPositionY() const;

private:
    size_t positionX_;
    size_t positionY_;
};
