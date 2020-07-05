#include "fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {
    timeToRotten_ = 100;
}

Fruit::Fruit(const std::string& name, size_t amount, double basePrice, size_t timeToRotten)
    : Cargo(name, amount, basePrice), timeToRotten_(timeToRotten) {}

void Fruit::nextDay() {
    timeElapsed_++;
    operator--();
}

std::string Fruit::getInfo() const {
    auto ss = std::stringstream{};
    ss << std::left << std::setw(5) << "Name: " << getName()
       << std::left << std::setw(5) << "\tAmount: " << getAmount()
       << std::left << std::setw(5) << "\tTime to rotten: " << getTimeToRotten() << '\n';
    return ss.str();
}

Fruit& Fruit::operator--() {
    if (timeToRotten_ > 0) {
        timeToRotten_--;
    }
    return *this;
}

Cargo& Fruit::operator+=(const size_t& amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t& amount) {
    if (amount_ >= amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Fruit::operator==(Cargo& fruit) const {
    return getName() == fruit.getName() &&
           getBasePrice() == fruit.getBasePrice() &&
           getPrice() == fruit.getPrice();
}
