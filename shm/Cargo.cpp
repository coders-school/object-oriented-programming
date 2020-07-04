#include "Cargo.h"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_(name),
      amount_(amount),
      basePrice_(basePrice) {}
