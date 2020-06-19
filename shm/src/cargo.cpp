#include "cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, double basePrice)
    : name_(name),
      amount_(amount),
      basePrice_(basePrice) {}

/*Cargo& Cargo::operator-=(const size_t& amount) {
    if (amount_ - amount >= 0) {
        amount_ -= amount;
    }
    return *this;
}*/

bool Cargo::operator==(const Cargo& freight2) {
    return name_ == freight2.name_;
}

Fruit::Fruit(std::string name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}

Alcohol::Alcohol(std::string name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}

Item::Item(std::string name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}
