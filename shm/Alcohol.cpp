#include "Alcohol.h"

Alcohol::Alcohol(std::string& name, size_t amount, size_t base_price, size_t power)
    : Cargo(name, amount, base_price), power_(power){};

//override from Cargo
size_t Alcohol::getPrice() const {
    return basePrice_ * (power_ / max_power);
}
