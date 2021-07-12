#include "shm/inc/Alcohol.hpp"

#include <stdexcept>

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage)
    : Cargo(name, amount, basePrice), percentage_(percentage) {}

Cargo& Alcohol::operator+=(size_t amount) {
    if (amount_ + amount > MAX_AMOUNT_OF_CARGO) {
        throw std::out_of_range("Maximum amount of alcohol reached!");
    }
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Alcohol)) {
        const Alcohol* alcohol = static_cast<const Alcohol*>(&cargo);
        return name_ == alcohol->getName() && basePrice_ == alcohol->getBasePrice() &&
               percentage_ == alcohol->getPercentage();
    }
    return false;
}

size_t Alcohol::getPrice() const {
    // FIXME:
    return basePrice_ * percentage_ / MAX_PERCENTAGE;
}

void Alcohol::nextDay() {
    daysUntilOnePercentEvaporates_--;
    if (percentage_ > 0 && daysUntilOnePercentEvaporates_ == 0) {
        percentage_--;
        daysUntilOnePercentEvaporates_ = 5;
    } 
}

size_t Alcohol::getPercentage() const {
    return percentage_;
}

bool Alcohol::isExpired() const {
    return percentage_;
}
