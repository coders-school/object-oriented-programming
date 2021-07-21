#include "Fruit.hpp"
#include <assert.h>
#include <iostream>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime)
    : Cargo(name, amount, basePrice), Perishable{freshTime, maxFreshTime} {
    if (!maxFreshTime) {
        maxFreshTime_ = freshTime_;
    }
    removeSuffix(suffix);
    addSuffix(suffix);
}

bool Fruit::operator==(const Cargo& other) const {
    if (const auto* otherFruit = dynamic_cast<const Fruit*>(&other)) {
        return name_ == otherFruit->getName() and maxFreshTime_ == otherFruit->maxFreshTime_ and freshTime_ == otherFruit->freshTime_;
    }
    return false;
}

Fruit& Fruit::operator--() {  //prefix operator
    if (freshTime_) {
        --freshTime_;
    }
    return *this;
}

size_t Fruit::getPrice() const {
    if (!maxFreshTime_ or !freshTime_) {
        return 0u;
    }
    const size_t price = std::max(static_cast<size_t>(static_cast<double>(basePrice_ * freshTime_) / static_cast<double>(maxFreshTime_)), 1ul);
    return price;
}

void Fruit::nextDay() {
    --(*this);
    std::cout << name_ << " best before: " << freshTime_ << '\n';
}

std::unique_ptr<Cargo> Fruit::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<Fruit>(name_, amount, basePrice_, freshTime_, maxFreshTime_);
    assert(*result == *this);
    return result;
}
