#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice)
        : Cargo(name, amount, basePrice) {}

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override {
        return static_cast<size_t>(basePrice_ * daysToRot_ / expirationDays_);
    }
    void nextDay() override { --(*this); }

    size_t getDaysToRot() const { return daysToRot_; }
    size_t getExpirationDays() const { return expirationDays_; }

    Fruit& operator--();

    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;

    bool operator==(const Cargo& cargo) const override;
    bool operator!=(const Cargo& cargo) const override;

private:
    size_t daysToRot_ = 10;
    const size_t expirationDays_ = 10;
};

