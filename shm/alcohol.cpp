#include "alcohol.hpp"
#include <iostream>

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage)
        : Cargo(name, amount, basePrice), percentage_(percentage) {} ;

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * static_cast<float>(percentage_)/static_cast<float>(MaxPercentage));
}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
 if (amount <= amount_) {
        amount_ -= amount;
    } else if(amount_ < 0){
        std::cerr << "Amount of cargo can not be under 0!!!\n";
    }
    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
        return cargo.getName() == getName();
}