#include "Fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t daysToRot)
    : Cargo(name, amount, basePrice), daysToRot_(daysToRot) {
}

Fruit& Fruit::operator--() {
    daysToRot_ == 0 ? /*do nothing*/ : --daysToRot_;
    return *this;
}

Cargo& Fruit::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
        return *this;
    }
    amount_ -= amount;
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    return getName() == cargo.getName() &&
           getBasePrice() == cargo.getBasePrice() &&
           getPrice() == cargo.getPrice();
}

bool Fruit::operator!=(const Cargo& cargo) const {
    return getName() != cargo.getName() ||
           getBasePrice() != cargo.getBasePrice() ||
           getPrice() != cargo.getPrice();
}
