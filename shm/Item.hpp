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
    Item(std::string name, size_t amount, size_t basePrice, Quality quality)
        : Cargo(name, amount, basePrice), quality_{quality} {}

    size_t getPrice() const override {
        return static_cast<size_t>(basePrice_ * static_cast<size_t>(quality_) / 100.0);
    }

    bool operator==(const Cargo& other) const override {
        if (auto otherItem = dynamic_cast<const Item*>(&other)) {
            return name_ == otherItem->getName() and quality_ == otherItem->quality_;
        }
        return false;
    }

    std::unique_ptr<Cargo> split(size_t amountPart) override {
        if (!amountPart or amountPart > amount_) {
            return {};
        }
        *this -= amountPart;
        return std::make_unique<Item>(name_, amountPart, basePrice_, quality_);
    }

protected:
    Quality quality_ = Quality::common;
};
