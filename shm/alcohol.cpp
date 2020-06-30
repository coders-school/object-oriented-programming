
#include "alcohol.hpp"

#include <string>

Alcohol::Alcohol(std::string name, size_t amount, size_t basePrice, size_t alcoholPower)
    : Cargo(name, amount, basePrice), alcoholPower_(alcoholPower) {
}

bool Alcohol::equals(const Cargo& rhs) const {
    const Alcohol* rAlcohol = dynamic_cast<const Alcohol*>(&rhs);
    if (!rAlcohol)
        return false;
    return (name_ == rAlcohol->name_ &&
            alcoholPower_ == rAlcohol->alcoholPower_);
}
