#include "Cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_{name}, amount_{amount}, basePrice_{basePrice} {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
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

////////////////////////////////////

size_t CargoDefault::getPrice() const {
    return basePrice_;
}

bool CargoDefault::operator==(const Cargo& other) const {
    return name_ == other.getName();
}

std::unique_ptr<Cargo> CargoDefault::split(size_t amountPart) {
    if (!amountPart or amountPart > amount_) {
        return {};
    }
    *this -= amountPart;
    return std::make_unique<CargoDefault>(name_, amountPart, basePrice_);
}
