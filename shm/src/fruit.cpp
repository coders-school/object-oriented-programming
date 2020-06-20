#include "fruit.hpp"

Fruit::Fruit(std::string name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}