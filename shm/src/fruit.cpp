#include "fruit.hpp"

Fruit::Fruit(std::string name, size_t amount, double basePrice, size_t timeToRotten)
    : Cargo(name, amount, basePrice), timeToRotten_(timeToRotten) {
    price_ = setPrice();
}

double Fruit::setPrice() {
    return basePrice_ * (1 / std::exp(getTimeToRotten()));
}

void Fruit::nextDay() {
    timeToRotten_--;
}
