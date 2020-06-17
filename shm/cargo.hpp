#pragma once

#include <string>

class Cargo {
public:
    Cargo();
    Cargo(std::string name, size_t ammount, double basePrice)
        : name_(name),
          ammount_(ammount),
          basePrice_(basePrice) {}

    Cargo&
    operator+=(const size_t& ammount) {
        ammount_ += ammount;
        return *this;
    }
    Cargo& operator-=(const size_t& ammount) {
        if (ammount_ - ammount >= 0) {
            ammount_ -= ammount;
        }
        return *this;
    }

    std::string getName() const { return name_; };
    size_t getAmmount() const { return ammount_; };
    double getBasePrice() const { return basePrice_; };

private:
    std::string name_;
    size_t ammount_;
    double basePrice_;
};
