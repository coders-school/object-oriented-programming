#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name), basePrice_(basePrice), amount_(amount) {}
