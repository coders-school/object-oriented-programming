#include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}

Alcohol::Alcohol(const std::string& name, size_t amount, double basePrice, double volume)
    : Cargo(name, amount, basePrice), volume_(volume) {}

double Alcohol::getPrice() const {
    return volume_ == 0.96 ? getBasePrice()
                           : getBasePrice() - getBasePrice() * (0.96 - getVolume());
}

std::string Alcohol::getInfo() const {
    auto ss = std::stringstream {};
    ss
            << std::left << std::setw(10) << name_
            << std::left << std::setw(5) << amount_
            << std::left << std::setw(5) << getBasePrice()
            << std::left << std::setw(5) << volume_
            << std::left << std::setw(5) << "-----"
            << std::left << std::setw(8) << "--------";
    return ss.str();
}

Cargo& Alcohol::operator+=(const size_t& amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(const size_t& amount) {
    if (amount_ >= amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Alcohol::operator==(Cargo& alcohol) const {
    return getName() == alcohol.getName() &&
           getBasePrice() == alcohol.getBasePrice() &&
           getPrice() == alcohol.getPrice();
}
