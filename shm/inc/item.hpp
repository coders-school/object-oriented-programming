#pragma once

#include <string>
#include <memory>

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 4,
        epic = 8,
        legendary = 16
    };

    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity, Time* time)
            : Cargo(name, amount, basePrice, time)
            , rairty_(rarity)
    {}
    
    Item& operator--();
    Item& operator--(int);
    bool operator==(const Cargo& item) const;
    bool operator!=(const Cargo& item) const;
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Rarity getRarity() const;

    void nextDay() override;

    std::unique_ptr<Cargo> clone() override;

private:
    const Rarity rairty_;
};
