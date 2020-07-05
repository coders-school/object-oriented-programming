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
    auto ss = std::stringstream{};
    ss << std::left << std::setw(5) << "Name: " << getName()
       << std::left << std::setw(5) << "\tAmount: " << getAmount()
       << std::left << std::setw(5) << "\tItem rarity: " << enumToString(getRarity()) << '\n';
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

std::string Item::enumToString(Rarity rarity) const {
    const std::map<Rarity, std::string> enumStrings{
        {Rarity::common, "common"},
        {Rarity::rare, "rare"},
        {Rarity::epic, "epic"},
        {Rarity::legendary, "legendary"}};
    auto it = enumStrings.find(rarity);
    return it == enumStrings.end() ? "Out of range" : it->second;
}