#include "shm/inc/Fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice)
   : Cargo(name, amount, basePrice)
{}

Fruit& Fruit::operator--() {
    if (rottenTime_ != 0) {
        rottenTime_--;
    }
    return *this;
}

std::size_t Fruit::getPrice() const {
    return basePrice_ * (rottenTime_ / DAYS_TO_ROTTEN);
}

Cargo& Fruit::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    if (cargo.getName() == name_ && cargo.getBasePrice() == basePrice_) {
        return true;
    }
    return false;
}
