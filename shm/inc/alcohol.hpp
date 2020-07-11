#pragma once

#include <memory>
#include <string>

#include "cargo.hpp"
#include "time.hpp"

namespace {
constexpr size_t MAX_STRENGTH = 96;
}

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t strength, Time* time)
        : Cargo(name, amount, basePrice, time),
          strength_(strength)
    {
    }

    Alcohol& operator--();
    Alcohol& operator--(int);
    bool operator==(const Cargo& alcohol) const override;
    bool operator!=(const Cargo& alcohol) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getStrength () const;

    std::unique_ptr<Cargo> clone() override;

    void nextDay();

private:
    const size_t strength_;
};
