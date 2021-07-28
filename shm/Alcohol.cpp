#include "Alcohol.hpp"

namespace {
constexpr auto maxPercentage = 96;
constexpr size_t alcoholPriceFor96percent = 100u;
}  // namespace

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
    if (const auto* otherAlcohol = dynamic_cast<const Alcohol*>(&other)) {
        return name_ == otherAlcohol->getName() and percentage_ == otherAlcohol->percentage_;
    }
    return false;
}

size_t Alcohol::getPrice() const {
    return std::max(static_cast<size_t>(static_cast<double>(basePrice_ * static_cast<size_t>(percentage_)) / static_cast<double>(maxPercentage)), 1ul);
}

std::unique_ptr<Cargo> Alcohol::createAmountOfEqual(size_t amount) {
    return std::make_unique<Alcohol>(name_, amount, percentage_);
}
