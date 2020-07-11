#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {
}
