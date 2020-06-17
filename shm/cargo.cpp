#include "cargo.hpp"

Cargo();
Cargo(size_t amount, std::string name, size_t base_price)
    : amount_(amount), name_(name), base_price_(base_price)
{}
~Cargo() {;} 

std::string getName() const { return name_; }
size_t getAmount() const { return amount_; }
size_t getBase_price() const { return base_price_; }

bool operator == (Cargo& cargo) { 
    return (name_ == cargo.name_) && (amount_ == cargo.amount_) && (base_price_ == cargo.base_price_);
}

