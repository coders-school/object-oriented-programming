#include "fruit.hpp"

Fruit::Fruit(std::string &name, size_t amount, size_t basePrice,
             size_t daysToExpiry)
    : Cargo{name, amount, basePrice}, daysToExpiry_{daysToExpiry} {};

// bool Fruit::operator==(Cargo &cargo) const {}

size_t Fruit::getPrice() const {}

std::string Fruit::getName() const { return name_; }
size_t Fruit::getAmount() const { return amount_; }
size_t Fruit::getBasePrice() const { return basePrice_; }