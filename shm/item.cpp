#include "item.hpp"

Item::Item(std::string name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {}

// bool Item::equals(const Cargo& rhs) const {
//     const Item* rItem = dynamic_cast<const Item*>(&rhs);
//     if (!rItem) {
//         return false;
//     }
//     return (name_ == rItem->name_ &&
//             basePrice_ == rItem->basePrice_ &&
//             rarity_ == rItem->rarity_);
// }