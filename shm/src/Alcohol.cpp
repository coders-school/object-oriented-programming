#include "shm/inc/Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage) 
    : Cargo(name, amount, basePrice)
    , percentage_(percentage)
{}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}
