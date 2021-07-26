#include "Fruit.hpp"

Fruit::Fruit(const std::string& name, const size_t amount, const size_t basePrice):
    Cargo(name, amount, basePrice),
    maxFreshness_(10),
    freshness_(maxFreshness_)
{}

Fruit& Fruit::operator--() {
    freshness_ = (freshness_ > 0)? freshness_ - 1 : 0;
    return *this;
}

size_t Fruit::getPrice() const {
    return static_cast<size_t>(static_cast<double>(getBasePrice()) * (freshness_ / maxFreshness_));
}

std::string Fruit::getName() const { 
    return "Fruit: " + name_; 
}

size_t Fruit::getAmount() const { 
    return amount_; 
}

size_t Fruit::getBasePrice() const { 
    return basePrice_; 
}
