#include "dryFruit.hpp"

#include <string>

Fruit& DryFruit::operator--() {
    spoilDelay_--;
    if (spoilDelay_ == 0) {
        Fruit::operator--();
        spoilDelay_ = drySpoilDelay;
    }
    return *this;
}

size_t DryFruit::getPrice() const {
    return Fruit::getPrice() * drynessPriceMultiplier;
}

void DryFruit::nextDay() {
    this->operator--();
}
