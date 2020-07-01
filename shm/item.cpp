#include "item.hpp"

#include <iostream>
#include <random>

Item::Item(std::string name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {}

bool Item::equals(const Cargo& rhs) const {
    const Item* rItem = dynamic_cast<const Item*>(&rhs);
    if (!rItem) {
        return false;
    }
    return (name_ == rItem->name_ &&
            basePrice_ == rItem->basePrice_ &&
            rarity_ == rItem->rarity_);
}

std::string Item::checkRarity() {
    switch (rarity_) {
    case Rarity::common:
        return "common";
        break;
    case Rarity::epic:
        return "epic";
        break;
    case Rarity::legendary:
        return "legendary";
        break;
    case Rarity::rare:
        return "rare";
        break;
    default:
        return "error: there`s no rarity";
        break;
    }
    return "";
}

void Item::nextDay() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 100);
    if (dist6(rng) > 90) {
        rarity_ = static_cast<Rarity>(static_cast<int>(rarity_) + 1);
        std::cout << "Oh no! One of your crew member dropped your " << name_
                  << "and it lost it`s rarity :( now it`s just " << checkRarity();
    }
}
