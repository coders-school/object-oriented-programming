#include "Fruit.h"

Fruit::Fruit(std::string& name, size_t amount, size_t base_price, size_t expiry_date)
    : Cargo(name, amount, base_price), expiry_date_(expiry_date){};

//override from Cargo
size_t Fruit::getPrice() const {
    if (time_elapsed_ >= expiry_date_) {
        return 0;
    }
    return basePrice_ * (time_elapsed_ / expiry_date_);
}

size_t Fruit::GetTimeElapsed() const {
    return time_elapsed_;
}

size_t Fruit::GetExpiryDate() const {
    return expiry_date_;
}
