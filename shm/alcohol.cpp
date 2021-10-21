#include "alcohol.hpp"
#include <iostream>
#include <limits>

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage)
        : Cargo(name, amount, basePrice), percentage_(percentage) {} ;

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * static_cast<float>(percentage_) / static_cast<float>(MaxPercentage));
}

std::shared_ptr<Cargo> Alcohol::clone(const size_t &amount) const {
    return std::make_shared<Alcohol>(this->getName(),
                                    amount,
                                    this->getBasePrice(),
                                    this->getPercentage());
}
