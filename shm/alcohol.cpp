#include "alcohol.hpp"

Alcohol::Alcohol(std::string name, size_t amount, size_t alcoholByVolume)
    : Cargo(name, amount, alcoholByVolume_){};

bool Alcohol::operator==(Cargo &cargo) const {}

size_t Alcohol::getPrice() const {
  if (alcoholByVolume_ < maxAlcoholByVolume_) {
    return basePrice_ * alcoholByVolume_ / maxAlcoholByVolume_;
  }
  return basePrice_;
}

std::string Alcohol::getName() const { return name_; }
size_t getAmount() const { return amount_; }
size_t getBasePrice() const { return basePrice_; }