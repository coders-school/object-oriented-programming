#include "Cargo.hpp"
#include <limits>

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice){};

Cargo& Cargo::operator+=(size_t amount) {
    
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(size_t amount) {
    if(amount_ < amount){
        amount_ = std::numeric_limits<size_t>::min();
    }
    else{
        amount_ -= amount;
    }
    return *this;
}
bool Cargo::operator==(const Cargo& cargo) {
    return (name_ == cargo.getName()) && (basePrice_ == cargo.getBasePrice());
}

