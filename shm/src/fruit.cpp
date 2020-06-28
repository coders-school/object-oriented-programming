#include "fruit.hpp"

#include <typeinfo>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t timeToSpoil)
    : Cargo(name, amount, basePrice), timeToSpoil_(timeToSpoil) {}

size_t Fruit::getPrice() const {
    return static_cast<size_t>(basePrice_ * (float(timeToSpoil_) / expiryDate_));
}

Fruit& Fruit::operator--() {
    --timeToSpoil_;
    return *this;
}

Cargo& Fruit::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(size_t amount) {
    (amount_ <= amount) ? amount_ = 0 : amount_ -= amount;
    return *this;
}

bool Fruit::operator==(const Cargo& other) const {
    if (typeid(*this).hash_code() != typeid(other).hash_code()) {
        return false;
    }
    return (amount_ == other.getAmount() && basePrice_ == other.getBasePrice() &&
            name_ == other.getName() && getPrice() == other.getPrice());
}

void Fruit::nextDay() {
    operator--();
}
