#include "shm/inc/Fruit.hpp"

#include <iostream>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice) 
        : Cargo(name, amount, basePrice) {
}

Fruit& Fruit::operator--() {
    if (rottenTime != 0){
        rottenTime--;
    } else {
        std::cerr << "Fruit is completely rotten\n";
    }
    return *this;
}

std::size_t Fruit::getPrice() const {
    return basePrice_ * (rottenTime / 10);
}
