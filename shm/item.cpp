#include "item.hpp"

Item::Item(std::string &name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo{name, amount, basePrice}, rarity_{rarity} {}

size_t Item::getPrice() const {
  switch (rarity_) {
  case Rarity::common:
    return basePrice_;
  case Rarity::rare:
    return (basePrice_ * 1.25);
  case Rarity::epic:
    return (basePrice_ * 1.5);
  case Rarity::legendary:
    return (basePrice_ * 2);
  }
  std::string Item::getName() const { return name_; }
  size_t Item::getAmount() const { return amount_; }
  size_t Item::getBasePrice() const { return basePrice_; }
  // Cargo &operator+=(size_t amount){}
  // Cargo &operator-=(size_t amount);
  // bool operator==(Cargo &cargo) const;