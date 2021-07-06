#include "Alcohol.hpp"
#include <assert.h>

size_t Alcohol::alcoholBasePriceFor96percent_ = alcoholBasePriceFor96percent;

Alcohol::Alcohol(std::string name, size_t amount, unsigned char percentage)
    : Cargo(name, amount, alcoholBasePriceFor96percent), percentage_{percentage} {
    if (percentage_ > maxPercentage) {
        percentage_ = maxPercentage;
    }
}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * percentage_ / static_cast<double>(maxPercentage));
}

bool Alcohol::operator==(const Cargo& other) const {
    if (auto otherAlcohol = dynamic_cast<const Alcohol*>(&other)) {
        return name_ == otherAlcohol->getName() and percentage_ == otherAlcohol->percentage_;
    }
    return false;
}

std::unique_ptr<Cargo> Alcohol::createAmountOfEqual(size_t amount) {
    using OwnType = std::remove_reference_t<decltype(*this)>;
    auto result = std::make_unique<OwnType>(name_, amount, percentage_);
    assert(*result == *this);
    return result;
}
