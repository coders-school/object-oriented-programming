#include "Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, const size_t amount, const size_t basePrice, const size_t voltage):
    Cargo(name, amount, basePrice),
    voltage_(voltage)
{}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(static_cast<double>(getBasePrice()) * (static_cast<double>(voltage_) / 96.));
}

std::string Alcohol::getName() const { 
    return "Alcohol: " + name_; 
}

size_t Alcohol::getAmount() const { 
    return amount_; 
}

size_t Alcohol::getBasePrice() const { 
    return basePrice_; 
}
