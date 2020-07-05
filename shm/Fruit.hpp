#pragma once

#include "Cargo.hpp"
class Fruit : public Cargo
{
public:
    Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date);
    Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date, size_t time_elapsed);
    Fruit(size_t amount, const Fruit* fruit);

    ~Fruit() override = default;

    void Print() const override = 0;

    [[nodiscard]] std::string GetName() const override;
    [[nodiscard]] size_t GetPrice() const override;
    [[nodiscard]] size_t GetAmount() const override;
    [[nodiscard]] size_t GetBasePrice() const override;

    Fruit& operator+=(size_t amount) override;
    Fruit& operator-=(size_t amount) override;

    bool operator==(const Cargo& cargo) const override;
    bool operator!=(const Cargo& cargo) const override;

    [[nodiscard]] size_t GetTimeElapsed() const;
    [[nodiscard]] size_t GetExpiryDate() const;

private:
    size_t time_elapsed_{};
    size_t expiry_date_;
};
