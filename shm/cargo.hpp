#pragma once

class Cargo {
public:
    Cargo& operator+=(const size_t ammount) {
        ammount_ += ammount;
        return *this;
    }
    Cargo& operator -=(const int ammount) {
        if (ammount_ - ammount >= 0) {
            ammount_ -= ammount;
        }
        return *this;
    }
private:
    std::string name_;
    size_t ammount_;
    double basePrice_;
};
