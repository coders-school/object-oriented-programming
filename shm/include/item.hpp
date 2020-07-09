#pragma once

#include <iostream>
#include <map>

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
    Rarity getRarity() const { return rarity_; }
    std::string getInfo() const override;

    std::string enumToString(Rarity rarity) const;

    void nextDay() override {}

    Cargo&
    operator+=(const size_t& amount) override;
    Cargo& operator-=(const size_t& amount) override;
    bool operator==(Cargo& item) const override;

private:
    Rarity rarity_;
};
