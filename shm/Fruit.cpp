#include "Fruit.h"

#include <algorithm>

Fruit::Fruit(std::string name, size_t amount, size_t base_price, Time* time, size_t expiry_date)
    : Cargo(name, amount, base_price, time), expiry_date_(expiry_date) {}

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
size_t Fruit::getPrice() const {
    if (time_elapsed_ >= expiry_date_) {
        return 0;
    }
    return basePrice_ * (time_elapsed_ / expiry_date_);
}

//override from Cargo
void Fruit::nextDay() {
    time_elapsed_++;
}

//override from Cargo
bool Fruit::operator==(Cargo& cargo) const {
    Fruit* otherFruit = dynamic_cast<Fruit*>(std::addressof(cargo));

    if (!otherFruit) {
        return false;
    }

    return name_ == otherFruit->name_ && amount_ == otherFruit->amount_ && basePrice_ == otherFruit->basePrice_ && expiry_date_ == otherFruit->expiry_date_ && time_elapsed_ == otherFruit->time_elapsed_;
}

Fruit& Fruit::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else {
        amount_ -= amount;
    }

    return *this;
}

size_t Fruit::getExpiryDate() const {
    return expiry_date_;
}

size_t Fruit::getTimeElapsed() const {
    return time_elapsed_;
}

//override from Cargo
std::string Fruit::getDescription() const {
    size_t time_to_rot;
    if (this->expiry_date_ < this->time_elapsed_) {
        time_to_rot = 0;
    } else {
        time_to_rot = this->expiry_date_ - this->time_elapsed_;
    }
    return "Name: " + this->name_ + " Time to rot: " + std::to_string(time_to_rot) + " Amount: " + std::to_string(this->amount_) + " Price: " + std::to_string(this->getPrice());
}
