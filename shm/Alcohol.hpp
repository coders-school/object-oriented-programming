#include "Cargo.hpp"

constexpr size_t maximumAlcoholContent = 96;

class Alcohol : public Cargo {
public:
    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override {
        return static_cast<size_t>(basePrice_ * alcoholContent_ / maximumAlcoholContent);
    }

    size_t getAlcoholContent() const { return alcoholContent_; }

private:
    const size_t alcoholContent_ = 96;
};
