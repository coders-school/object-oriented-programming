#include "DryFruit.hpp"

DryFruit::DryFruit(const std::string& name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime)
: Fruit(name, amount, basePrice, freshTime, maxFreshTime), counter_(0) {}

DryFruit& DryFruit::operator--(){
    if (freshTime_ && counter_ >=9) {
        --freshTime_;
        counter_ = 0;
    } else {
        ++counter_;
    }

    return *this;
}

size_t DryFruit::getPrice() const {
    if (!maxFreshTime_ or !freshTime_) {
        return 0u;
    }
    const size_t price = std::max(3*static_cast<size_t>(basePrice_ * freshTime_ / static_cast<double>(maxFreshTime_)),1ul);
    return price;
}

std::unique_ptr<Cargo> DryFruit::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<DryFruit>(name_, amount, basePrice_, freshTime_, maxFreshTime_);
    assert(*result == *this);
    return result;
}


