#pragma once

#include "Cargo.hpp"
#include "Rottingable.hpp"

class Fruit : public Cargo, public Rottingable {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime = 0);
    virtual ~Fruit() = default;

    bool operator==(const Cargo& other) const override;

    Fruit& operator--() override;

    size_t getPrice() const override;

    static constexpr std::string_view suffix = " (Fruit)";

protected:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
