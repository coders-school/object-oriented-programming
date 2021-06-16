#include "../inc/Cargo.hpp"
#include <iostream>

Cargo& Cargo::operator+=(const size_t value) {
    amount_ += value;
    return *this;
}

Cargo& Cargo::operator-=(const size_t value) {
    if (value <= amount_) {
        amount_ -= value;
    } else {
        std::cout << "Amount of cargo can't be under 0\n";
    }
    return *this;
}
