#pragma once

#include "Fruit.hpp"

class DryFruit : public Fruit {
public:
    static constexpr std::string_view suffix = " (DryFruit)";
    static constexpr size_t freshMultiplier = 10;
    static constexpr size_t priceMultiplier = 3;

    DryFruit(const std::string& name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime = 0);
    ~DryFruit() override = default;

    bool operator==(const Cargo& other) const override;
    DryFruit& operator--();

    size_t getPrice() const override;

protected:
    size_t counter_ = 0;

private:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
