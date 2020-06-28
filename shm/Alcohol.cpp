#include "Alcohol.hpp"

Cargo& Alcohol::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(const size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
        return *this;
    }
    amount_ -= amount;

    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    return getName() == cargo.getName() &&
           getBasePrice() == cargo.getBasePrice() &&
           getPrice() == cargo.getPrice();
}