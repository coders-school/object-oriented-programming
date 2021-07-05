#include "shm/inc/Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage) 
    : Cargo(name, amount, basePrice)
    , percentage_(percentage)
{}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Alcohol::operator==(const Cargo& alcohol) const {
    // TODO:
    return alcohol.getAmount() == amount_ ? true : false;
}

size_t Alcohol::getPrice() const {
    // FIXME:
    return basePrice_ * percentage_ / MAX_PERCENTAGE;
}

size_t Alcohol::getPercentage() const {
    return percentage_;
}
