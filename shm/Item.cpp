#include "Item.hpp"
#include <assert.h>

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

std::unique_ptr<Cargo> Item::createAmountOfEqual(size_t amount) {
    using OwnType = std::remove_reference_t<decltype(*this)>;
    auto result = std::make_unique<OwnType>(name_, amount, basePrice_, quality_);
    assert(*result == *this);
    return result;
}