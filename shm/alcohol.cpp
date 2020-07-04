#include "alcohol.hpp"

#include <iostream>
#include <typeinfo>

Alcohol::Alcohol(uint32_t amount, const std::string& name, uint32_t basePrice, int32_t power)
    : Cargo(amount, name, basePrice), power_(power) {}

Alcohol::~Alcohol() {}

std::string Alcohol::getName() const {
    return "Alcohol " + name_;
}

uint32_t Alcohol::getAmount() const {
    return amount_;
}

uint32_t Alcohol::getBasePrice() const {
    return basePrice_;
}

double Alcohol::getPrice() const {
    return basePrice_ * (power_ / maxAlcohol_);
}

int32_t Alcohol::getPower() const {
    return power_;
}

Cargo& Alcohol::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(uint32_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    std::cout << "There is no so many alcohol!\n";
    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    auto alcohol = dynamic_cast<const Alcohol&>(cargo);
    if (typeid(cargo) != typeid(*this)) {
        return false;
    }
    return (name_ == alcohol.getName()) && (amount_ == alcohol.getAmount()) && (basePrice_ == alcohol.getBasePrice()) &&
           (power_ == alcohol.getPower());
}

void Alcohol::nextDay() {
    power_--;
   // std::cout << "Next day in: " << getName() << "\n";
}

std::shared_ptr<Cargo> Alcohol::clone() const {
    return std::make_shared<Alcohol>(*this);
}
