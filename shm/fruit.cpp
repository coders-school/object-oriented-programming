#include "fruit.hpp"

#include <iostream>

Fruit::Fruit(uint32_t amount, const std::string& name, uint32_t basePrice, int32_t expiryDate)
    : Cargo(amount, name, basePrice), expiryDate_(expiryDate), currentExpiryDate_(expiryDate) {}

Fruit::~Fruit() {}

std::string Fruit::getName() const {
    return "Fruit " + name_;
}

uint32_t Fruit::getAmount() const {
    return amount_;
}

uint32_t Fruit::getBasePrice() const {
    return basePrice_;
}

int32_t Fruit::getExpiryDate() const {
    return currentExpiryDate_;
}

double Fruit::getPrice() const {
    if (currentExpiryDate_ == 0 || expiryDate_ == 0) {
        return 0;
    }
    return basePrice_ * currentExpiryDate_ / expiryDate_ + NOFLOAT_ROUNDING;
}

Fruit& Fruit::operator--() {
    if (currentExpiryDate_ > 0) {
        --currentExpiryDate_;
    } else {
        std::cout << "Fruits already rotten!";
    }
    return *this;
}

Cargo& Fruit::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(uint32_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    std::cout << "There is no so many fruits!";
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    auto fruit = dynamic_cast<const Fruit&>(cargo);
    if (typeid(*this) != typeid(cargo)) {
        return false;
    }
    return (fruit.getBasePrice() == basePrice_) && (fruit.getName() == name_) &&
           (fruit.getExpiryDate() == currentExpiryDate_);
}

void Fruit::nextDay() {
    operator--();
    //std::cout << "Next day in: " << getName() << "\n";
}

std::shared_ptr<Cargo> Fruit::clone() const {
    return std::make_shared<Fruit>(*this);
}
