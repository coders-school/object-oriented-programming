#include "Item.hpp"
#include <assert.h>

Item::Item(std::string name, size_t amount, size_t basePrice, Quality quality)
    : Cargo(name, amount, basePrice), quality_{quality} 
{
    removeSuffix(suffix);
    addSuffix(suffix);
}

bool Item::operator==(const Cargo& other) const {
    if(const auto* otherItem = dynamic_cast<const Item*>(&other)){
        return name_ == otherItem->getName() and quality_ == otherItem->quality_;
    }
    return false;
}

size_t Item::getPrice() const {
    return static_cast<size_t>(basePrice_ * static_cast<size_t>(quality_) / 100.0);
}

std::unique_ptr<Cargo> Item::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<Item>(name_, amount, basePrice_, quality_);
    assert(*result == *this);
    return result;
}
