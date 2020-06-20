#pragma once

#include <cmath>
#include <string>

enum class Rarity { common = 1,
                    rare = 3,
                    epic = 6,
                    legendary = 10 };

class Cargo {
public:
    Cargo() = default;
    Cargo(std::string name, size_t amount, double basePrice);
    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual double getBasePrice() const = 0;
    virtual double getPrice() const = 0;
    virtual size_t getExpiryDate() const = 0;
    virtual double getPercentage() const = 0;
    virtual Rarity getRarity() const = 0;
    virtual Cargo& operator--() = 0;
    virtual Cargo& operator+=(const size_t& amount) = 0;
    virtual Cargo& operator-=(const size_t& amount) = 0;
    bool operator==(const Cargo& freight2);

protected:
    std::string name_;
    size_t amount_;
    double basePrice_;
};