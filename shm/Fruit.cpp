#include "Fruit.hpp"
#include <assert.h>

void addFruitNaming(std::string& name) {
    constexpr std::string_view suffix = " (Fruit)";
    std::string_view sv(name);
    auto trim_pos = sv.find(suffix, sv.npos - suffix.npos);//should sheck only suffix
    if (trim_pos != sv.npos) {
        return;
    }
    name += suffix;
}

Fruit::Fruit(std::string name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime)
    : Cargo(name, amount, basePrice), freshTime_{freshTime}, maxFreshTime_{maxFreshTime} {
    if (!maxFreshTime) {
        maxFreshTime_ = freshTime_;
    }
    addFruitNaming(name_);
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

size_t Fruit::getPrice() const {
    if (!maxFreshTime_) {
        return 0u;
    }
    return static_cast<size_t>(basePrice_ * freshTime_ / static_cast<double>(maxFreshTime_));
}

std::unique_ptr<Cargo> Fruit::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<Fruit>(name_, amount, basePrice_, freshTime_, maxFreshTime_);
    assert(*result == *this);
    return result;
}
