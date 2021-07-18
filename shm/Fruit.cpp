#include "Fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t shelfLife)
    : Cargo(name, amount, basePrice), shelfLife_(shelfLife) {}

Fruit& Fruit::operator++() {
    timeInCargoRoom_++;
    return *this;
}