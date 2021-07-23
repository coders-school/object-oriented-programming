#pragma once

#include "Cargo.hpp"

#include <memory>
#include <string>

class CargoDefault : public Cargo {
public:
    using Cargo::Cargo;
    ~CargoDefault() override = default;

    bool operator==(const Cargo& other) const override;

    size_t getPrice() const override;

private:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
