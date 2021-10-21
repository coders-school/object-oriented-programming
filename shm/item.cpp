#include "item.hpp"
#include <limits>

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity){};

std::shared_ptr<Cargo> Item::clone(const size_t &amount) const {
    return std::make_shared<Item>(this->getName(),
                                amount,
                                this->getBasePrice(),
                                this->getRarity());
}
