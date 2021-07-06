#include "Alcohol.hpp"

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

std::unique_ptr<Cargo> Alcohol::split(size_t amountPart) {
    if (!amountPart or amountPart > amount_) {
        return {};
    }
    *this -= amountPart;
    return std::make_unique<Alcohol>(name_, amountPart, percentage_);
}
