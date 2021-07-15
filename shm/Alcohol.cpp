#include "Alcohol.hpp"
#include <assert.h>
//#include <string_view>

size_t Alcohol::alcoholBasePriceFor96percent_ = alcoholPriceFor96percent;

Alcohol::Alcohol(std::string name, size_t amount, unsigned char percentage)
    : Cargo(name, amount, alcoholBasePriceFor96percent_), percentage_{percentage} {
    if (percentage_ > maxPercentage) {
        percentage_ = maxPercentage;
    }
    removeSuffix(suffix);
    addSuffix(suffix);
}

bool Alcohol::operator==(const Cargo& other) const {
    if(const auto* otherAlcohol = dynamic_cast<const Alcohol*>(&other)){
        return name_ == otherAlcohol->getName()
            and percentage_ == otherAlcohol->percentage_;
    }
    return false;
}

size_t Alcohol::getPrice() const {
    auto result = static_cast<size_t>(static_cast<double>(basePrice_ * static_cast<size_t>(percentage_)) / static_cast<double>(maxPercentage));
    result = std::max(result, 1ul);
    return result;
}

std::unique_ptr<Cargo> Alcohol::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<Alcohol>(name_, amount, percentage_);
    assert(*result == *this);
    return result;
}
