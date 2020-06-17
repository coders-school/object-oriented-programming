#include "ship.hpp"

#include <iostream>

Ship& Ship::operator-=(size_t num) {
    crew_ -= num;
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    return *this;
}

Cargo Ship::getCargo(size_t index) const {
    if (index < 0 || index >= cargo_.size()) {
        std::cerr << "Invalid index\n";
    }
    return cargo_[index];
}
