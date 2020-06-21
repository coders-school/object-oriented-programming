#include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name,
                 size_t amount,
                 size_t basePrice,
                 size_t percentage)
    : Cargo(name, amount, basePrice), percentage_(percentage) {}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * (float(percentage_)) / maxPercentage_); 
}
