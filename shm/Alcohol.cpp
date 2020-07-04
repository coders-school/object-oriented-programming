#include "Alcohol.hpp"

Cargo& Alcohol::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(const size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
        return *this;
    }
    amount_ -= amount;
    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    return getName() == cargo.getName() &&
           getBasePrice() == cargo.getBasePrice() &&
           getPrice() == cargo.getPrice();
}

bool Alcohol::operator!=(const Cargo& cargo) const {
    return getName() != cargo.getName() ||
           getBasePrice() != cargo.getBasePrice() ||
           getPrice() != cargo.getPrice();
}

Alcohol::Alcohol(const std::string &name, size_t amount, size_t basePrice, size_t alcoholContent)
    : Cargo(name, amount, basePrice), alcoholContent_(alcoholContent) {

}
