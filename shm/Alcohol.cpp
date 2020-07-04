#include "Alcohol.h"

Alcohol::Alcohol(std::string& name, size_t amount, size_t base_price, size_t power)
    : Cargo(name, amount, base_price), power_(power){};

//override from Cargo
size_t Alcohol::getPrice() const {
    return basePrice_ * (power_ / max_power);
}

//override from Cargo
bool Alcohol::operator==(Cargo& cargo) const {
    Alcohol* otherAlcohol = dynamic_cast<Alcohol*>(std::addressof(cargo));

    if (!otherAlcohol) {
        return false;
    }

    return name_ == otherAlcohol->name_ && amount_ == otherAlcohol->amount_ && basePrice_ == otherAlcohol->basePrice_ && power_ == otherAlcohol->power_;
}
