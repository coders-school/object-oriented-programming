#include "fruit.hpp"

Fruit::Fruit(std::string name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}

void Fruit::nextDay() {
    timeToRotten_--;
    if (timeToRotten_ == 0) {
        delete this;
    }
}
