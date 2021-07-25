#include "alcohol.hpp"

Alcohol::Alcohol(std::string &name, size_t amount, size_t basePrice,
                 size_t alcoholByVolume)
    : Cargo{name, amount, basePrice}, alcoholByVolume_{alcoholByVolume} {}

bool Alcohol::operator==(Cargo &cargo) const {}

size_t Alcohol::getPrice() const {
  if (alcoholByVolume_ < maxAlcoholByVolume_) {
    return basePrice_ * alcoholByVolume_ / maxAlcoholByVolume_;
  }
  return basePrice_;
}
std::string Alcohol::getName() const { return name_; }
size_t Alcohol::getAmount() const { return amount_; }
size_t Alcohol::getBasePrice() const { return basePrice_; }

// in game.hpp make this function work when "currentDay.endCurrentDay()" in time.hpp happens 5 times
size_t Alcohol::nextDay() {
  return --alcoholByVolume_;
}
