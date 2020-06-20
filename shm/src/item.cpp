#include "item.hpp"

Item::Item(std::string name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}