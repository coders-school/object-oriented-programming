#pragma once

#include "Cargo.hpp"

class Alcohol : public Cargo
{
public:
    Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage);
//    Alcohol(size_t amount, const Alcohol* alcohol);  TODO

    ~Alcohol() override = default;

    void Print() const override = 0;

    [[nodiscard]] std::string GetName() const override;
    [[nodiscard]] size_t GetPrice() const override;
    [[nodiscard]] size_t GetAmount() const override;
    [[nodiscard]] size_t GetBasePrice() const override;

    Alcohol& operator+=(size_t amount) override;
    Alcohol& operator-=(size_t amount) override;

    bool operator==(const Cargo& cargo) const override;
    bool operator!=(const Cargo& cargo) const override;

    [[nodiscard]] size_t GetPercentage() const;

private:
    size_t percentage_;
};
