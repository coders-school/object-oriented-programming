#pragma once

#include "Cargo.h"

class Fruit : public Cargo {
public:
    Fruit(std::string& name, size_t amount, size_t base_price, size_t expiry_date);
    ~Fruit() override;

    size_t getPrice() const override;

    bool operator==(const Cargo& cargo) const override;

    size_t GetTimeElapsed() const;
    size_t GetExpiryDate() const;

private:
    size_t time_elapsed_{0};
    size_t expiry_date_;
};
