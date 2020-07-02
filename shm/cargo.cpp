#include "cargo.hpp"

#include <iostream>

Cargo::Cargo(uint32_t amount, std::string name, uint32_t basePrice)
    : amount_(amount), name_(name), basePrice_(basePrice) {
    // time_->registerObserver(this);
}

Cargo::~Cargo() {
    // time_->unregisterObserver(this);
}

// bool Cargo::operator==(Cargo& cargo) {
//     return (name_ == cargo.name_) && (amount_ == cargo.amount_) && (basePrice_ == cargo.basePrice_);
// }

// void Cargo::nextDay() {
//     std::cout << "Next day in: " << getName() << "\n";
// }
