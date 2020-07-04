#pragma once

#include <string>
#include <utility>
#include <vector>

class Cargo
{
public:
    Cargo() : amount_(0), base_price_(0) {}
    Cargo(size_t amount, std::string name, size_t basePrice)
        : amount_(amount), name_(std::move(name)), base_price_(basePrice)
    {
    }

    virtual ~Cargo() = default;

    virtual void Print() const = 0;

    [[nodiscard]] virtual std::string GetName() const = 0;
    [[nodiscard]] virtual size_t GetPrice() const = 0;
    [[nodiscard]] virtual size_t GetAmount() const = 0;
    [[nodiscard]] virtual size_t GetBasePrice() const = 0;

    virtual Cargo& operator+=(size_t amount) = 0;
    virtual Cargo& operator-=(size_t amount) = 0;

    virtual bool operator==(const Cargo& cargo) const = 0;
    virtual bool operator!=(const Cargo& cargo) const = 0;

protected:
    std::string name_;
    size_t base_price_;
    size_t amount_;
};
