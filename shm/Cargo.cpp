#include "Cargo.h"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_(name),
      amount_(amount),
      basePrice_(basePrice) {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else {
        amount_ -= amount;
    }

    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return name_ == cargo.name_ && amount_ == cargo.amount_ && basePrice_ == cargo.basePrice_;
}

std::string Cargo::getName() const {
    return name_;
}

size_t Cargo::getAmount() const {
    return amount_;
}

size_t Cargo::getBasePrice() const {
    return basePrice_;
}

size_t Cargo::getPrice() const {
    return basePrice_;
}
