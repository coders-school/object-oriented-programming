#pragma once

#include <string>

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common = 1, rare = 3, epic = 6, legendary = 10 };
    Item(uint32_t amount, const std::string& name, uint32_t basePrice, Rarity rarity);
    ~Item() override;

    std::string getName() const override;
    uint32_t getAmount() const override;
    uint32_t getBasePrice() const override;
    double getPrice() const override;
    Rarity getRarity() const;
    Cargo& operator+=(uint32_t amount) override;
    Cargo& operator-=(uint32_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    void nextDay() override{};
    virtual std::shared_ptr<Cargo> clone() const override;

private:
    const Rarity rarity_;
};
