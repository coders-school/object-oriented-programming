#include "shm/inc/Fruit.hpp"

#include <stdexcept>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice)
   : Cargo(name, amount, basePrice)
{}


size_t Fruit::getPrice() const {
    return basePrice_ * (rottenTime_ / DAYS_TO_ROTTEN);
}

Cargo& Fruit::operator+=(const size_t amount) {
    if (amount_ + amount > MAX_AMOUNT_OF_CARGO) {
        throw std::out_of_range("Maximum amount of fruits reached!");
    }
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    }
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    if (cargo.getName() == name_ && cargo.getBasePrice() == basePrice_) {
        return true;
    }
    return false;
}

void Fruit::nextDay() {
    operator--();
}

Fruit& Fruit::operator--() {
    if (rottenTime_ != 0) {
        rottenTime_--;
    }
    return *this;
}
