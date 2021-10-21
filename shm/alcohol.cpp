#include "alcohol.hpp"
#include <iostream>
#include <limits>

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage)
        : Cargo(name, amount, basePrice), percentage_(percentage) {} ;

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * static_cast<float>(percentage_)/static_cast<float>(MaxPercentage));
}

//Cargo& Alcohol::operator+=(size_t amount) {
//    if (amount_ + amount < std::numeric_limits<size_t>::max()) {
//        amount_ += amount;
//    }
//    return *this;
//}
//
//Cargo& Alcohol::operator-=(size_t amount) {
//    if (amount_ >= amount ) {
//        amount_ -= amount;
//    }
//    return *this;
//}
//
//bool Alcohol::operator==(const Cargo& cargo) const {
//    return cargo.getName() == getName();
//}

std::shared_ptr<Cargo> Alcohol::clone(const size_t &amount) const {
    return std::make_shared<Alcohol>(this->getName(),
                                    amount,
                                    this->getBasePrice(),
                                    this->getPercentage());
}