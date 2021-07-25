#include "fruit.hpp"

Fruit::Fruit(std::string &name, size_t amount, size_t basePrice,
             size_t daysToExpiry)
    : Cargo{name, amount, basePrice}, daysToExpiry_{daysToExpiry} {};

// bool Fruit::operator==(Cargo &cargo) const {}

size_t Fruit::getPrice() const { return basePrice_; }

std::string Fruit::getName() const { return name_; }
size_t Fruit::getAmount() const { return amount_; }
size_t Fruit::getBasePrice() const { return basePrice_; }

// in game.hpp make this function work when "currentDay.endCurrentDay()" in time.hpp happens
size_t nextDay(size_t daysToExpiry_, size_t amount, size_t basePrice_) {
    --daysToExpiry_;
    --basePrice_;
    if(daysToExpiry_ == 0) {
        amount = 0;
    }
    return daysToExpiry_, amount, basePrice_;
}
