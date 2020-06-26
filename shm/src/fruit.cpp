#include "fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {
    timeToRotten_ = 100;
}

Fruit::Fruit(const std::string& name, size_t amount, double basePrice, size_t timeToRotten)
    : Cargo(name, amount, basePrice), timeToRotten_(timeToRotten) {}

void Fruit::nextDay() {
    //todo: operator-- for object can be better here?
    //timeToRotten_--;
    timeElapsed_++;
    operator--();
}

Fruit& Fruit::operator--() {
    if (timeToRotten_ > 0) {
        timeToRotten_--;
    }
    return *this;
}

Cargo& Fruit::operator+=(const size_t& amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t& amount) {
    if (amount_ >= amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Fruit::operator==(Cargo& fruit) const {
    return getName() == fruit.getName() &&
           getBasePrice() == fruit.getBasePrice() &&
           getPrice() == fruit.getPrice();
}
