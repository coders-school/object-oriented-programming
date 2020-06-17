#include "cargo.hpp"

Cargo::Cargo()
    : Cargo("", 0, 0) {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount_ >= amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(std::string name) {
    return name_ == name;
}

std::string Cargo::GetName() const {
    return name_;
}
size_t Cargo::GetAmount() const {
    return amount_;
}
size_t Cargo::GetBasePrice() const {
    return basePrice_;
}

bool Cargo::operator==(std::string name) {
    return name_ == name;
}
