#pragma once

#include <memory>
#include <string>

class Cargo {
public:
    Cargo(std::string name, size_t amount, size_t basePrice);

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    virtual bool operator==(const Cargo& other) const = 0;

    virtual size_t getPrice() const = 0;

    virtual std::string getName() const;
    virtual size_t getAmount() const;
    virtual size_t getBasePrice() const;

    virtual std::unique_ptr<Cargo> split(size_t amountPart) = 0;

protected:
    std::string name_{};
    size_t amount_{};
    size_t basePrice_{};
};

//temporary for same Functionality as old Cargo
class CargoDefault : public Cargo {
public:
    using Cargo::Cargo;

    size_t getPrice() const override {
        return basePrice_;
    }

    bool operator==(const Cargo& other) const override {
        return name_ == other.getName();
    }

    std::unique_ptr<Cargo> split(size_t amountPart) override {
        if (!amountPart or amountPart > amount_) {
            return {};
        }
        *this -= amountPart;
        return std::make_unique<CargoDefault>(name_, amountPart, basePrice_);
    }
};
