#include "cargo.hpp"

#include <iostream>

Cargo::Cargo(uint32_t amount, std::string name, uint32_t basePrice)
    : amount_(amount), name_(name), basePrice_(basePrice) {}

Cargo::~Cargo() {}
