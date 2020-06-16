#pragma once
#include <cstddef>

class Coordinates {
public:
    Coordinates() = default;
    Coordinates(size_t, size_t);
    bool operator==(const Coordinates&) const;

private:
    size_t positionX_{0};
    size_t positionY_{0};
};
