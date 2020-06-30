#include "cargo.hpp"

#include <iostream>

Cargo::Cargo(uint32_t amount, std::string name, uint32_t basePrice, Time* time)
    : amount_(amount), name_(name), basePrice_(basePrice), time_(time) {
    time_->registerObserver(this);
}

Cargo::~Cargo() {
    time_->unregisterObserver(this);
}

std::string Cargo::getName() const {
    return name_;
}

uint32_t Cargo::getAmount() const {
    return amount_;
}

uint32_t Cargo::getBasePrice() const {
    return basePrice_;
}

Cargo& Cargo::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(uint32_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    std::cout << "There is no so many cargo!";
    return *this;
}

bool Cargo::operator==(Cargo& cargo) {
    return (name_ == cargo.name_) && (amount_ == cargo.amount_) && (basePrice_ == cargo.basePrice_);
}

void Cargo::nextDay() {
    std::cout << "Next day in: " << getName() << "\n";
}
