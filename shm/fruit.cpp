#include "fruit.hpp"

#include <iostream>

Fruit::Fruit(std::string name, size_t amount, size_t basePrice, size_t timeToExpire)
    : Cargo(name, amount, basePrice), timeToExpire_(timeToExpire) {
}

Fruit& Fruit::operator--() {
    if (timeToExpire_ == 0) {
        std::cerr << "Fruit rotten\n";
        return *this;
    }
    --timeToExpire_;
    return *this;
}

bool Fruit::equals(const Cargo& rhs) const {
    const Fruit* rFruit = dynamic_cast<const Fruit*>(&rhs);
    if (!rFruit) {
        return false;
    }
    return (name_ == rFruit->name_ &&
            timeToExpire_ == rFruit->timeToExpire_);
}

void Fruit::nextDay() {
    Fruit::operator--();
}
