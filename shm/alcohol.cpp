
#include "alcohol.hpp"

#include <iostream>
#include <random>
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

void Alcohol::nextDay() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 100);
    if (dist6(rng) > 50) {
        std::cout << "Oh no! Someone drank your alcohol and added water so no one would notice!"
                  << "your alcohol lost it`s power :( now it`s " << --alcoholPower_ << '\n';
    }
}
