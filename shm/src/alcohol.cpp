 #include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice)
    : Alcohol(name, amount, basePrice, maxPower_) {}

size_t Alcohol::GetPrice() const {
    return static_cast<uint16_t>(static_cast<float>(basePrice_) * (power_ / maxPower_));
} 
size_t Alcohol::getAmount() const {
     return amount_; }

std::string Alcohol::GetName() const {
      return name_;
}
bool Alcohol::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Alcohol&))
        return false;
    
    auto alcohol = static_cast<const Alcohol*>(&cargoToCheck);
    return name_ == alcohol->GetName() &&
           amount_ == alcohol->getAmount() &&
           basePrice_ == alcohol->getBasePrice() &&
           power_ == alcohol->getPower();
}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    if (amount >= amount_) {
        amount_ = 0;
    } else
        amount_ -= amount;

    return *this;
}
