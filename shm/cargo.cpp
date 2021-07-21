
#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
        : name_(name)
        , amount_(amount)
        , basePrice_(basePrice){}
        
Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount_ <= amount) {
        amount_ = 0;
    } else {
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(Cargo& cargo) {
    return cargo.getName() == name_ && cargo.getAmount() == amount_;
}
 
size_t Cargo::addAmount(size_t addedAmount) {
     amount_ += addedAmount;
 }
 size_t Cargo::dellAmount(size_t deletedAmount) {
    if(amount_ <= deletedAmount) {
        amount_ = 0;
    }
    else {
        amount_ -= deletedAmount;
    }
    
 }