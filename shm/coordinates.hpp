#pragma once
#include <cmath>

class Coordinates {
public:
    Coordinates();

    Coordinates(size_t positionX, size_t positionY);

    void setPositionX(size_t );
    size_t getPositionX() const;

    void setPositionY(size_t );
    size_t getPositionY() const;

    bool operator== (const Coordinates& ) const;

    size_t distance(const Coordinates&);

private:
    size_t positionX_;
    size_t positionY_;
};
