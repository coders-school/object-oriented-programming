#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : _name(name),
      _amount(amount),
      _basePrice(basePrice) {}
