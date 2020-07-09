#pragma once

#include <iomanip>
#include <sstream>
#include <string>

#include "time.hpp"

class Cargo : public Observer {
public:
    Cargo() = default;
    Cargo(std::string name, size_t amount, double basePrice);
    virtual ~Cargo() = default;

    virtual std::string getName() const {
        return name_;
    }
    virtual size_t getAmount() const {
        return amount_;
    }
    virtual double getBasePrice() const {
        return basePrice_;
    }
    virtual double getPrice() const = 0;
    virtual std::string getInfo() const = 0;

    virtual Cargo& operator+=(const size_t& amount) = 0;
    virtual Cargo& operator-=(const size_t& amount) = 0;
    virtual bool operator==(Cargo& cargo) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Cargo* cargo);

protected:
    std::string name_;
    size_t amount_;
    double basePrice_;
};
