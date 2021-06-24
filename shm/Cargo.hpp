#pragma once
#include <string>

class Cargo {
public:
    bool operator==(const Cargo& cargo) const {
        if (name_ != cargo.getName()) {
            return false;
        }
        if (amount_ != cargo.getAmount()) {
            return false;
        }
        if (basePrice_ != cargo.getBasePrice()) {
            return false;
        }
        return true;    
    }

    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(size_t amount) {
        amount_ -= amount;
        return *this;
    }

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
