#pragma once

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate);
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate, size_t leftTime);
    ~Fruit() override = default;

    virtual Fruit& operator--();

    size_t getLeftTime() const { return leftTime_; }

    size_t getTimeToSpoil() const { return timeToSpoil_; }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }

protected:
    // override from Cloneable<Cargo>
    Cargo* cloneToRawPointer() override { return new Fruit(*this); }

private:
    const size_t timeToSpoil_;
    size_t leftTime_ = timeToSpoil_;
};
