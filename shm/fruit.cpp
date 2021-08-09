#include "fruit.hpp"
#include <iostream>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expirationDate)
         : Cargo(name, amount, basePrice), expirationDate_(expirationDate) {};

size_t Fruit::getPrice() const  {
    return static_cast<size_t>( basePrice_ * static_cast<float>(purchaseDate_)/ expirationDate_);
}

Cargo& Fruit::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount of cargo can not be under 0!!!\n";
    }
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    return cargo.getName() == getName();
}

Fruit& Fruit::operator--() {
    if(purchaseDate_ <= 0) {
        purchaseDate_ = 0;
    }
    purchaseDate_--;
    return *this;
}

Fruit Fruit::operator--(int) {
    if(purchaseDate_ <= 0) {
        purchaseDate_ = 0;
    }
    purchaseDate_--;
    return *this;
}