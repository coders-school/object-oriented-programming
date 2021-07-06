#pragma once

#include "Cargo.hpp"

enum class Quality : size_t {
    common = 80,
    rare = 100,
    epic = 110,
    legendary = 125
};

class Item : public Cargo {
public:
    Item(std::string name, size_t amount, size_t basePrice, Quality quality);
    ~Item() override = default;

    size_t getPrice() const override;
    bool operator==(const Cargo& other) const override;

protected:
    Quality quality_ = Quality::common;

private:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
