#pragma once

#include <string>

class Cargo {
 public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);
    Cargo(const Cargo& cargo);
    virtual ~Cargo() = default;

    virtual bool operator==(const Cargo& cargo) const = 0;
    virtual bool operator!=(const Cargo& cargo) const = 0;
    virtual Cargo& operator+=(const size_t amount) = 0;
    virtual Cargo& operator-=(const size_t amount) = 0;

    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

    void setAmount(const size_t amount) { amount_ = amount; }
    virtual Cargo* clone() = 0;

 protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
