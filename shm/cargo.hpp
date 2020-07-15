#pragma once

#include <memory>
#include <string>

class Cargo {
public:
    Cargo();
    Cargo(std::string name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;
    virtual std::shared_ptr<Cargo> Clone() = 0;

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& cargo) const;

    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    void setAmount(size_t amount) { amount_ = amount; }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
