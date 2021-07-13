#pragma once

#include <memory>
#include <string>
#include "Cargo.hpp"

//temporary for same Functionality as old Cargo
class CargoDefault : public Cargo {
public:
    using Cargo::Cargo;
    ~CargoDefault() override = default;

    bool operator==(const Cargo& other) const override;

    size_t getPrice() const override;

    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
