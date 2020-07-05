#pragma once

#include <cstddef>

class Coordinates {
public:
    Coordinates() = default;
    Coordinates(size_t pos_x, size_t pos_y);
    static double distance(const Coordinates& lhs, const Coordinates& rhs);
    bool operator==(const Coordinates& lhs) const;

private:
    size_t pos_x_{0};
    size_t pos_y_{0};
};
