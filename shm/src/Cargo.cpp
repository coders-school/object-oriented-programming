#include "shm/inc/Cargo.hpp"

#include <stdexcept>

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice) 
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
{}

void Cargo::setAmount(size_t amount) {
    if (amount > MAX_AMOUNT_OF_CARGO) {
        throw std::out_of_range("Maximum amount of cargo reached!");
    }
    amount_ = amount;
} 
