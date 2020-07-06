#include "alcohol.hpp"

size_t Alcohol::getPrice() const {
    return static_cast<size_t>((static_cast<float>(timeToSpoilLeft_) /
                                static_cast<float>(timeToSpoil_)) * 
                                static_cast<float>(basePrice_));
}

std::string Alcohol::getName() const { return name_; }
size_t Alcohol::getAmount() const { return amount_; }
size_t Alcohol::getBasePrice() const { return basePrice_; }
size_t Alcohol::getTimeToSpoil() const { return timeToSpoil_; }
size_t Alcohol::getTimeToSpoilLeft() const { return timeToSpoilLeft_; }

Alcohol& Alcohol::operator--() {
    if (timeToSpoilLeft_ > 0) {
        --timeToSpoilLeft_;
    }
    return *this;
}
Alcohol& Alcohol::operator--(int) {
    Alcohol& temp(*this);
    if (timeToSpoilLeft_ > 0) {
        operator--();
    }
    return temp;
}
bool Alcohol::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Alcohol)) {
        const Alcohol* alcohol = static_cast<const Alcohol*>(&cargo);
        return name_ == alcohol->getName() &&
            amount_ == alcohol->getAmount() &&
            basePrice_ == alcohol->getBasePrice() &&
            timeToSpoil_ == alcohol->getTimeToSpoil() &&
            timeToSpoilLeft_ == alcohol->getTimeToSpoilLeft();
    }
    return false;
}
bool Alcohol::operator!=(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Alcohol)) {
        const Alcohol* alcohol = static_cast<const Alcohol*>(&cargo);
        return !(this == alcohol);
    }
    return false;
}
Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}
Cargo& Alcohol::operator-=(size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    return *this;
}

Cargo* Alcohol::clone() {
    std::shared_ptr<Alcohol> sp_Alcohol = std::make_shared<Alcohol>(*this);
    return sp_Alcohol.get();
}

