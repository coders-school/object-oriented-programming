#pragma once

#include <string>

//class resposible for manage commodity in game
class Cargo {
public:
    Cargo(const std::string&, size_t, size_t);

    Cargo& operator+=(const size_t);
    Cargo& operator-=(const size_t);
    bool operator==(const Cargo&) const;

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

private:
    const std::string name_; 
    size_t amount_ {};
    size_t basePrice_ {}; 
};
