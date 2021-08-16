#pragma once

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    static size_t alcoholBasePriceFor96percent_;
    static constexpr std::string_view suffix = " (Alcohol)";

    Alcohol(std::string name, size_t amount, unsigned char percentage);
    ~Alcohol() override = default;

    bool operator==(const Cargo& other) const override;

    size_t getPrice() const override;

    unsigned char getPercentage() const { return percentage_; }

protected:
    unsigned char percentage_ = 0;

private:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
