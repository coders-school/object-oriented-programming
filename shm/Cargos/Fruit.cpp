#include "Fruit.hpp"
#include <cassert>
#include <iostream>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime)
    : Cargo(name, amount, basePrice), Perishable{freshTime, maxFreshTime} {
    removeSuffix(suffix);
    addSuffix(suffix);
}

bool Fruit::operator==(const Cargo& other) const {
    if (const auto* otherFruit = dynamic_cast<const Fruit*>(&other)) {
        return name_ == otherFruit->getName() and this->getPerishable() == otherFruit->getPerishable();
    }
    return false;
}

Fruit& Fruit::operator--() {
    if (getFreshTime()) {
        --this->getPerishable();
    }
    return *this;
}

size_t Fruit::getPrice() const {
    if (!getMaxFreshTime() or !getFreshTime()) {
        return 0u;
    }
    const size_t price = std::max<size_t>(static_cast<size_t>(static_cast<double>(basePrice_ * getFreshTime()) / static_cast<double>(getMaxFreshTime())), 1ul);
    return price;
}

void Fruit::nextDay() {
    --(*this);
    std::cout << name_ << " best before: " << getFreshTime() << '\n';
}

std::unique_ptr<Cargo> Fruit::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<Fruit>(name_, amount, basePrice_, getFreshTime(), getMaxFreshTime());
    assert(*result == *this);
    return result;
}
