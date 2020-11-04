#include "Cargo.hpp"

Cargo::Cargo(uint16_t amount, const std::string& name, uint16_t basePrice)
    : amount_(amount), name_(name), basePrice_(basePrice) {}
