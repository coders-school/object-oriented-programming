#include "fruit.hpp"

Fruit::Fruit(std::string name, size_t amount, size_t daysToExpiry)
    : Cargo(name, amount, daysToExpiry_){};

bool Fruit::operator==(Cargo &cargo) const {}

size_t Fruit::getPrice() const {
 
  }



std::string Fruit::getName() const { return name_; }
size_t getAmount() const { return amount_; }
size_t getBasePrice() const { return basePrice_; }