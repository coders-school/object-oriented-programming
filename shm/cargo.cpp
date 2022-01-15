#include <limits>
#include <iostream>
#include "cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice, Time* time)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , time_(time)
{
    time->attach(this);
}

Cargo& Cargo::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount)
{
    if (amount_ < amount) {
        amount_ = 0;
    }
    else {
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const
{
    return name_ == cargo.name_ && basePrice_ == cargo.basePrice_;
}

void Cargo::printCargo(int i) const {
    std::cout << i << ". "
              << "Cargo Name: " << name_ << ", amount: " << amount_ << ", price: " << getPrice() << '\n';
}

std::string Cargo::getCargoInfo() {
    return "Cargo Name: " + name_ + ", amount: " + std::to_string(amount_) + ", price: " + std::to_string(getPrice()) + '\n';
}

void Cargo::reduceAmount(size_t amount) {
    if ((int)(amount_) - (int)(amount) < 0) {
        amount_ = 0;
    }
    else {
        amount_ -= amount;
    }
}

void Cargo::increaseAmount(size_t amount)
{
    amount_ += amount;
}

void Cargo::setAmount(size_t amount)
{
    amount_ = amount;
}
