#include "DryFruit.hpp"
#include <cassert>

DryFruit::DryFruit(const std::string& name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime)
    : Fruit(name, amount, basePrice, freshTime, maxFreshTime), counter_(0) {
    removeSuffix(Fruit::suffix);
    removeSuffix(suffix);
    addSuffix(suffix);
}

bool DryFruit::operator==(const Cargo& other) const {
    if (const auto* otherDryFruit = dynamic_cast<const DryFruit*>(&other)) {
        return name_ == otherDryFruit->getName() 
            and this->getPerishable() == otherDryFruit->getPerishable();
    }
    return false;
}

DryFruit& DryFruit::operator--() {
    ++counter_;
    if (getFreshTime() && counter_ >= freshMultiplier) {
        --this->getPerishable();
        counter_ = 0;
    }
    return *this;
}

size_t DryFruit::getPrice() const {
    if (!getMaxFreshTime() or !getFreshTime()) {
        return 0u;
    }
    const size_t price = std::max(static_cast<size_t>(static_cast<double>(priceMultiplier * static_cast<size_t>(basePrice_ * getFreshTime())) / static_cast<double>(getMaxFreshTime())), 1ul);
    return price;
}

std::unique_ptr<Cargo> DryFruit::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<DryFruit>(name_, amount, basePrice_, getFreshTime(), getMaxFreshTime());
    assert(*result == *this);
    return result;
}
