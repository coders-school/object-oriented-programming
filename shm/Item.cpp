#include "Item.hpp"
#include <assert.h>

void addItemNaming(std::string& name) {
    constexpr std::string_view suffix = " (Item)";
    std::string_view sv(name);
    auto trim_pos = sv.find(suffix, sv.npos - suffix.npos);//should sheck only suffix
    if (trim_pos != sv.npos) {
        return;
    }
    name += suffix;
}

Item::Item(std::string name, size_t amount, size_t basePrice, Quality quality)
    : Cargo(name, amount, basePrice), quality_{quality} 
{
    addItemNaming(name_);
}

bool Item::operator==(const Cargo& other) const {
    if (auto otherItem = dynamic_cast<const Item*>(&other)) {
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
