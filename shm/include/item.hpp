#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common = 1,
                        rare = 3,
                        epic = 6,
                        legendary = 10 };

    Item(const std::string& name, size_t amount, double basePrice);
    Item(const std::string& name, size_t amount, double basePrice, Rarity rarity);
    ~Item() override {}

    double getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    Rarity getRarity() const { return rarity_; }

    void nextDay() {}

    Cargo& operator+=(const size_t& amount) override;
    Cargo& operator-=(const size_t& amount) override;
    bool operator==(Cargo& item) const override;

private:
    Rarity rarity_;
};
