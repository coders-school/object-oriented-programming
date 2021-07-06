#include "shm/inc/DryFruit.hpp"

DryFruit::DryFruit(const std::string& name, size_t amount, size_t basePrice)
        : Fruit(name, amount, basePrice) {
}

DryFruit& DryFruit::operator--() {
    rottenDryFruit_--;
    if (rottenTime_ != 0 && rottenDryFruit_ == 0) {
        rottenTime_--;
        rottenDryFruit_ = DAYS_TO_ROTTEN_DRY_FRUIT;
    }
    return *this;
}

std::size_t DryFruit::getPrice() const {
    return basePrice_ * (rottenTime_ / DAYS_TO_ROTTEN_DRY_FRUIT) * multiplierDryFruit_;
}

void DryFruit::nextDay() {
    operator--();
}
