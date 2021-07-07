#include "Fruit.hpp"
#include <assert.h>

Fruit::Fruit(std::string name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime)
    : Cargo(name, amount, basePrice), freshTime_{freshTime}, maxFreshTime_{maxFreshTime} {
    if (!maxFreshTime) {
        maxFreshTime_ = freshTime_;
    }
}

size_t Fruit::getPrice() const {
    if (!maxFreshTime_) {
        return 0u;
    }
    return static_cast<size_t>(basePrice_ * freshTime_ / static_cast<double>(maxFreshTime_));
}

bool Fruit::operator==(const Cargo& other) const {
    if (auto otherFruit = dynamic_cast<const Fruit*>(&other)) {
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

std::unique_ptr<Cargo> Fruit::createAmountOfEqual(size_t amount) {
    using OwnType = std::remove_reference_t<decltype(*this)>;
    auto result = std::make_unique<OwnType>(name_, amount, basePrice_, freshTime_, maxFreshTime_);
    assert(*result == *this);
    return result;
}
