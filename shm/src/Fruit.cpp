#include "shm/inc/Fruit.hpp"

#include <iostream>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice) 
        : Cargo(name, amount, basePrice) {
}

Fruit& Fruit::operator--() {
    if (rottenTime_ != 0) {
        rottenTime_--;
    }
    return *this;
}

std::size_t Fruit::getPrice() const {
    return basePrice_ * (rottenTime_ / 10);
}
