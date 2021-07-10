#include <stdexcept>

#include "Cargo.hpp"
#include <assert.h>

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_{name}, amount_{amount}, basePrice_{basePrice} {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount_ < amount) {
        throw std::invalid_argument("Not allowed! You will be below zero!");
    }
    amount_ -= amount;
    return *this;
}

<<<<<<< HEAD
const std::string& Cargo::getName() const {
=======
const std::string_view Cargo::getName() const {
>>>>>>> 13c0019d5c8997b33d01dc82cec9d9b0f68f8d4d
    return name_;
}

size_t Cargo::getAmount() const {
    return amount_;
}

size_t Cargo::getBasePrice() const {
    return basePrice_;
}

std::unique_ptr<Cargo> Cargo::split(size_t amountPart) {
    if (!amountPart or amountPart > amount_) {
        return {};
    }
    *this -= amountPart;
    return createAmountOfEqual(amountPart);
}
