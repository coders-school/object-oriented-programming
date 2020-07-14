#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

std::string Cargo::oneLineDescription() const {
    return getName() + "\t" + "Amount: " + std::to_string(getAmount());
}
