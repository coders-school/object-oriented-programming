#include "cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, double basePrice)
    : name_(name),
      amount_(amount),
      basePrice_(basePrice) {}

bool Cargo::operator==(Cargo& cargo) const {
    return name_ == cargo.name_;
}
