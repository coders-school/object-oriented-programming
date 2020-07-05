#include "Coordinates.h"

#include <cmath>

Coordinates::Coordinates(size_t pos_x, size_t pos_y)
    : pos_x_(pos_x), pos_y_(pos_y) {}

double Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    return std::sqrt((lhs.pos_x_ - rhs.pos_x_) * (lhs.pos_x_ - rhs.pos_x_) + (lhs.pos_y_ - rhs.pos_y_) * (lhs.pos_y_ - rhs.pos_y_));
}

bool Coordinates::operator==(const Coordinates& lhs) const {
    return this->pos_x_ == lhs.pos_x_ && this->pos_y_ == lhs.pos_y_;
}
