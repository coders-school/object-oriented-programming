#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t basePrice, size_t amount)
    : name_(name), basePrice_(basePrice), amount_(amount) {}
