#include "cargo.hpp"

Cargo::Cargo(std::string name, size_t ammount, double basePrice)
    : name_(name),
      ammount_(ammount),
      basePrice_(basePrice) {}

Cargo& Cargo::operator+=(const size_t& ammount) {
    ammount_ += ammount;
    return *this;
}
Cargo& Cargo::operator-=(const size_t& ammount) {
    if (ammount_ - ammount >= 0) {
        ammount_ -= ammount;
    }
    return *this;
}

bool Cargo::operator==(const Cargo& freight2) {
    return name_ == freight2.name_;
}

Fruit::Fruit(std::string name, size_t ammount, double basePrice)
    : Cargo(name, ammount, basePrice) {}
