#include "Item.hpp"

Item::Item(std::string name, size_t amount, size_t basePrice, Quality quality)
    : Cargo(name, amount, basePrice), quality_{quality} {}

size_t Item::getPrice() const {
    return static_cast<size_t>(basePrice_ * static_cast<size_t>(quality_) / 100.0);
}

bool Item::operator==(const Cargo& other) const {
    if (auto otherItem = dynamic_cast<const Item*>(&other)) {
        return name_ == otherItem->getName() and quality_ == otherItem->quality_;
    }
    return false;
}

std::unique_ptr<Cargo> Item::split(size_t amountPart) {
    if (!amountPart or amountPart > amount_) {
        return {};
    }
    *this -= amountPart;
    return std::make_unique<Item>(name_, amountPart, basePrice_, quality_);
}