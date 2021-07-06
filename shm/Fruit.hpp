#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime = 0);
    ~Fruit() override = default;

    size_t getPrice() const override;
    bool operator==(const Cargo& other) const override;
    Fruit& operator--();
    std::unique_ptr<Cargo> split(size_t amountPart) override;

protected:
    size_t maxFreshTime_ = 0;
    size_t freshTime_ = 0;
};
