#include "dryfruit.hpp"

size_t DryFruit::getPrice() const {
    if (time_elapsed_ >= expiry_date_)
        return 0;
    return static_cast<size_t>(3 * basePrice_ * ((float)(expiry_date_ - time_elapsed_)) / expiry_date_);
}

Cargo& DryFruit::operator--() {
    if (++counter_ == 10) {
        ++time_elapsed_;
        counter_ = 0;
    }
    return *this;
};

void DryFruit::nextDay() {
    if (basePrice_ - 1 == 0) {
        basePrice_ = 0;
    } else {
        basePrice_ -= 1;
    }
}