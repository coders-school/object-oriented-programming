#include "shm/inc/Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage) 
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , percentage_(percentage)
{}

Alcohol::~Alcohol() override = default;

Cargo& Alcohol::operator+=(size_t amount) {
    if (amount_ + amount > Ship::capacity_) {
        std::cerr << "Too much cargo\n";
        return *this;
    }
    amount_ += amount;
    return *this;
}

Cargo& operator-=(size_t amount) {
    if (amount_ < amount) {
        std::cerr << "Number of cargos below 0\n";
        return *this;
    }
    amount_ -= amount;
    return *this;
}
