#pragma once

#include "Cargo.hpp"

class Item : public Cargo
{
public:
    enum class Rarity
    {
        common = 1,
        rare = 4,
        epic = 8,
        legendary = 16
    };

    Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity);

    ~Item() override = default;

    void Print() const override;

    [[nodiscard]] std::string GetName() const override;
    [[nodiscard]] size_t GetPrice() const override;
    [[nodiscard]] size_t GetAmount() const override;
    [[nodiscard]] size_t GetBasePrice() const override;

    Item& operator+=(size_t amount) override;
    Item& operator-=(size_t amount) override;

    bool operator==(const Cargo& cargo) const override;
    bool operator!=(const Cargo& cargo) const override;

    [[nodiscard]] Item::Rarity GetRarity() const;

private:
    Rarity rarity_;
};
