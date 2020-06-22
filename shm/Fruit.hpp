#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override {
        return static_cast<size_t>(basePrice_ * daysToRot_ / expirationDays_);
    }

    size_t getDaysToRot() const { return daysToRot_; }
    size_t getExpirationDays() const { return expirationDays_; }

    Fruit& operator--();

private:
    size_t daysToRot_ = 10;
    const size_t expirationDays_ = 10;
};
