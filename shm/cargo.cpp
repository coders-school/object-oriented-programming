#include "cargo.hpp"

bool Cargo::operator==(const Cargo& cargo) const {
    return (name_ == cargo.name_) &&
           (amount_ == cargo.amount_) &&
           (basePrice_ == cargo.basePrice_);
}
bool Cargo::operator!=(const Cargo& cargo) const {
    return (name_ != cargo.name_) ||
           (amount_ != cargo.amount_) ||
           (basePrice_ != cargo.basePrice_);
}
Cargo& Cargo::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(const size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    return *this;
}
