#include "Cargo.hpp"
#include <iostream>

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

bool Cargo::operator==(const Cargo& other) const {
    return (name_ == other.name_
            //and amount_ == other.amount_
            //and basePrice_ == other.basePrice_
    );
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

std::unique_ptr<Cargo> Cargo::split(size_t amountPart) {
    if (!amountPart or amountPart > amount_) {
        return {};
    }

    *this -= amountPart;
    return std::make_unique<Cargo>(name_, amountPart, basePrice_);
}

void Cargo::nextDay() {
    std::cout << "Next Day in Cargo " << name_ << '\n';
}
