#include <iostream>
#include <string>

class Cargo {
private:
    const std::string name_;
    size_t amount_;
    double basePrice_;

public:
    Cargo& Cargo::operator+=(const size_t amount) {
        amount_ += amount;
        return *this;
    }

    Cargo& Cargo::operator-=(const size_t amount) {
        amount_ -= amount;
        return *this;
    }
};
