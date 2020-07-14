#include "dryfruit.hpp"

#include "globaltime.hpp"
Fruit& DryFruit::operator--() {
    spoilDelay_--;
    if (spoilDelay_ == 0) {
        Fruit::operator--();
        spoilDelay_ = kSpoilDelay;
    }
    return *this;
}

size_t DryFruit::getPrice() const {
    return Fruit::getPrice() * kDrynessPriceMultiplier;
}

std::string DryFruit::oneLineDescription() const {
    return Fruit::oneLineDescription() + " (dry)";
}

void DryFruit::nextDay() {
    this->operator--();
}

DryFruit::~DryFruit() {
    GlobalTime::getGlobalTime()->removeObserver(this);
}
