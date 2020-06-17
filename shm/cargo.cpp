#include <iostream>
#include <string>
#include "cargo.hpp"

    Cargo& Cargo::operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& Cargo::operator-=(size_t amount) {
        if (amount_ < amount) {
            std::cerr << "Cargo is lower than 0 \n";
            return *this;
        }
        amount_ -= amount;
        return *this;
    };

    bool Cargo::operator==(std::string name) {
        return (name_ == name);
    };


