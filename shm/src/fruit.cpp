#include "fruit.hpp"

Fruit::Fruit(const std::string& name,
             size_t amount,
             size_t basePrice,
             size_t expiryDate,
             size_t timeElapsed)
    : Cargo(name, amount, basePrice),
      expiryDate_(expiryDate),
      timeElapsed_(timeElapsed) {}

size_t Fruit::getPrice() const {
    if (timeElapsed_ >= expiryDate_) {
        return 0;
    }
    return static_cast<size_t>(basePrice_ * ((float)(expiryDate_ - timeElapsed_)) /
                               expiryDate_);
}

Fruit& Fruit::operator--() {
    --expiryDate_;
    return *this;
}
