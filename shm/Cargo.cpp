#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice, Time* time)
    : _name(name),
      _amount(amount),
      _basePrice(basePrice),
      _time(time) {
    _time->addObserver(this);
}

Cargo::~Cargo() {
    _time->removeObserver(this);
}