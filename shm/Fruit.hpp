#pragma once

#include "Cargo.hpp"
#include "Perishable.hpp"

class Fruit : public Cargo, public Perishable {
public:
    static constexpr std::string_view suffix = " (Fruit)";

    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime = 0);
    virtual ~Fruit() = default;

    bool operator==(const Cargo& other) const override;
    Fruit& operator--();

    size_t getPrice() const override;

    void nextDay() override;
   
private:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
