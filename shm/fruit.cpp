#include "cargo.hpp"
#include "fruit.hpp"
#include <string>

    //Override from Cargo
Fruit::Fruit(std::string name, size_t amount, size_t basePrice):
    Cargo(name, amount, basePrice){}

    size_t Fruit::getPrice() const {
        return basePrice_ * (timeToSpoil_ / expiryDate_);
    }
    std::string Fruit::getName() const {
        return name_;
    }
    size_t Fruit::getAmount() const {
        return amount_;
    }
    size_t Fruit::getBasePrice() const {
        return basePrice_;
    }
    
    Fruit& Fruit::operator--() {
        if (expiryDate_ == 0) {
            return *this;
        }
        --timeToSpoil_;
        return *this;
    }

