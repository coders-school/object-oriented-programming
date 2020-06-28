#pragma once

#include <string>
#include <utility>
#include <vector>

class Cargo
{
public:
    Cargo() : amount_(0), basePrice_(0) {}
    Cargo(size_t amount, std::string name, size_t basePrice)
        : amount_(amount), name_(std::move(name)), basePrice_(basePrice)
    {
    }

    virtual ~Cargo() = default;

    virtual void Print() const {};

    virtual std::string GetName() const {};

    [[nodiscard]] virtual size_t GetAmount() const;
    [[nodiscard]] virtual size_t GetBasePrice() const;

    virtual Cargo& operator+=(size_t amount);
    virtual Cargo& operator-=(size_t amount);

    friend bool operator==(const Cargo& lhs, const Cargo& rhs);
    friend bool operator!=(const Cargo& lhs, const Cargo& rhs);

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
