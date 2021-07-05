#pragma once

#include <memory>
#include <string>
#include "Time.hpp"
#include "Timeable.hpp"

class Cargo : public Timeable {
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(std::string name, size_t amount, size_t basePrice);
    ~Cargo();

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& other) const;

    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;
    size_t getPrice() const {
        return basePrice_;
    }

    void nextDay() override;

    std::unique_ptr<Cargo> split(size_t amountPart);

private:
    size_t timeId_ {0};
};
