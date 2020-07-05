#include "Alcohol.h"

#include <algorithm>

Alcohol::Alcohol(std::string name, size_t amount, size_t base_price, Time* time, size_t power)
    : Cargo(name, amount, base_price, time), power_(power) {}

//override from Cargo
std::string Cargo::getName() const {
    return name_;
}

//override from Cargo
size_t Cargo::getAmount() const {
    return amount_;
}

//override from Cargo
size_t Cargo::getBasePrice() const {
    return basePrice_;
}

//override from Cargo
size_t Alcohol::getPrice() const {
    return basePrice_ * (power_ / max_power);
}

//override from Cargo
void Alcohol::nextDay() {
    if (power_ > 0) {
        power_--;
    }
}

//override from Cargo
bool Alcohol::operator==(Cargo& cargo) const {
    Alcohol* otherAlcohol = dynamic_cast<Alcohol*>(std::addressof(cargo));

    if (!otherAlcohol) {
        return false;
    }

    return name_ == otherAlcohol->name_ && amount_ == otherAlcohol->amount_ && basePrice_ == otherAlcohol->basePrice_ && power_ == otherAlcohol->power_;
}

//override from Cargo
std::string Alcohol::getDescription() const {
    return "Name: " + this->name_ + " Power: " + std::to_string(this->power_) + " Amount: " + std::to_string(this->amount_) + " Price: " + std::to_string(this->getPrice());
}
