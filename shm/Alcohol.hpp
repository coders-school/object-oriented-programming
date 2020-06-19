#include "Cargo.hpp"

constexpr size_t maximumAlcoholConent = 96;

class Alcohol : public Cargo {
public:
    size_t getPrice() const override {
        return basePrice_ * alcoholContent / maximumAlcoholConent;
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

private:
    const size_t alcoholContent = 96;
};