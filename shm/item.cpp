#include "item.hpp"
#include <limits>

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity){};


//Cargo& Item::operator+=(size_t amount) {
//    if (amount_ + amount < std::numeric_limits<size_t>::max()) {
//        amount_ += amount;
//    }
//    return *this;
//}
//
//Cargo& Item::operator-=(size_t amount) {
//    if (amount_ >= amount ) {
//        amount_ -= amount;
//    }
//    return *this;
//}
//
//bool Item::operator==(const Cargo& cargo) const {
//    return cargo.getName() == getName();
//}

std::shared_ptr<Cargo> Item::clone(const size_t &amount) const {
    return std::make_shared<Item>(this->getName(),
                                amount,
                                this->getBasePrice(),
                                this->getRarity());
}
