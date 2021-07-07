#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, size_t basePrice, size_t freshTime, size_t maxFreshTime = 0);
    ~Fruit() override = default;
    
    bool operator==(const Cargo& other) const override;
    Fruit& operator--();

    size_t getPrice() const override;

protected:
    size_t maxFreshTime_ = 0;
    size_t freshTime_ = 0;

private:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
