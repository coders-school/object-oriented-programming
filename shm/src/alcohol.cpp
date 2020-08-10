 #include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name, uint16_t amount, uint16_t basePrice)
    : Alcohol(name, amount, basePrice, maxPower_) {}

uint16_t Alcohol::getPrice() const {
    return static_cast<uint16_t>(static_cast<float>(basePrice_) * (power_ / maxPower_));
} 
uint16_t Alcohol::getAmount() const {
     return amount_; }

std::string Alcohol::getName() const {
      return name_;
}
bool Alcohol::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Alcohol&))
        return false;
    
    auto alcohol = static_cast<const Alcohol*>(&cargoToCheck);
    return name_ == alcohol->getName() &&
           amount_ == alcohol->getAmount() &&
           basePrice_ == alcohol->getBasePrice() &&
           power_ == alcohol->getPower();
}

Cargo& Alcohol::operator+=(uint16_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(uint16_t amount) {
    if (amount >= amount_) {
        amount_ = 0;
    } else
        amount_ -= amount;

    return *this;
}
