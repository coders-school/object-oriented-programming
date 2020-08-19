#pragma once

#include <cstddef>

class Coordinates {
private:
    size_t positionX_{0};
    size_t positionY_{0};

public:
    Coordinates(size_t positionX, size_t positionY);
    
    bool operator==(const Coordinates& cord) const;
    bool operator!=(const Coordinates& cord) const;

    size_t getX() const { return positionX_; };
    size_t getY() const { return positionY_; };

    static size_t distance(const Coordinates& lhs, const Coordinates& rhs);
};
