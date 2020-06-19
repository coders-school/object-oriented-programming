#include "cargo.hpp"

class Cargo {
  public:
Cargo();
Cargo(uint32_t amount, std::string name, uint32_t base_price)
    : amount_(amount), name_(name), base_price_(base_price)
{}
~Cargo() {;} 

std::string getName() const { return name_; }
uint32_t getAmount() const { return amount_; }
uint32_t getBase_price() const { return base_price_; }

bool operator == (Cargo& cargo) { 
    return (name_ == cargo.name_) && (amount_ == cargo.amount_) && (base_price_ == cargo.base_price_);
}

};
