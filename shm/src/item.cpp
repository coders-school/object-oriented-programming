#include "item.hpp"

Item::Item(const std::string& name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {
    rarity_ = Rarity::common;
}

Item::Item(const std::string& name, size_t amount, double basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {}

double Item::getPrice() const {
    return getBasePrice() * static_cast<int>(rarity_);
}

std::string Item::getInfo() const {
    auto ss = std::stringstream {};
    ss
            << std::left << std::setw(10) << name_
            << std::left << std::setw(5) << amount_
            << std::left << std::setw(5) << getBasePrice()
            << std::left << std::setw(5) << "-----"
            << std::left << std::setw(5) << "-----"
            << std::left << std::setw(8) << enumToString(rarity_);
    return ss.str();
}

Cargo& Item::operator+=(const size_t& amount) {
    amount_ += amount;
    return *this;
}
Cargo& Item::operator-=(const size_t& amount) {
    if (amount_ >= amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Item::operator==(Cargo& item) const {
    return getName() == item.getName() &&
           getPrice() == item.getPrice() &&
           getBasePrice() == item.getBasePrice();
}