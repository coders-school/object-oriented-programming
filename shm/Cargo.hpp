#pragma once

#include <memory>
#include <string>

class Cargo {
public:
    Cargo(std::string name, size_t amount, size_t basePrice);

    virtual ~Cargo() = default;

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    virtual bool operator==(const Cargo& other) const = 0;

    virtual size_t getPrice() const = 0;

    virtual std::string getName() const;
    virtual size_t getAmount() const;
    virtual size_t getBasePrice() const;

    std::unique_ptr<Cargo> split(size_t amountPart) {
        if (!amountPart or amountPart > amount_) {
            return {};
        }
        *this -= amountPart;
        return createAmountOfEqual(amountPart);
    }

protected:
    std::string name_{};
    size_t amount_{};
    size_t basePrice_{};

private:
    virtual std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) = 0;
};

//temporary for same Functionality as old Cargo
class CargoDefault : public Cargo {
public:
    using Cargo::Cargo;
    ~CargoDefault() override = default;

    size_t getPrice() const override;
    bool operator==(const Cargo& other) const override;
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
