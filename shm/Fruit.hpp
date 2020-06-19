#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    size_t getPrice() const override {
        return basePrice_ * daysToRot_ / expirationDays_;
    }
    std::string getName() const override {
        return name_;
    }
    size_t getAmount() const override {
        return amount_;
    }
    size_t getBasePrice() const override {
        return basePrice_;
    }
    Fruit& operator--() {
        if (daysToRot_ == 0) {
            return *this;
        }
        --daysToRot_;
        return *this;
    }

private:
    size_t daysToRot_ = 10;
    const size_t expirationDays_ = 10;
};