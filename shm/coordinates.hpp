#pragma once
#include <cstddef>

class Coordinates {
public:
    Coordinates(size_t, size_t);
    bool operator==(const Coordinates&) const;

private:
    size_t positionX_;
    size_t positionY_;
};
