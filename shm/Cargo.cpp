#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {
}

Cargo& Cargo::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
        return *this;
    }
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return (name_ == cargo.name_);
}

bool Cargo::operator!=(const Cargo& cargo) const {
    return (name_ != cargo.name_);
}
