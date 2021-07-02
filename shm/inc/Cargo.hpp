#pragma once

#include <string>

//class resposible for manage commodity in game
class Cargo {
public:
    //constructs an object of cargo in game
    Cargo(const std::string& name, size_t amount, size_t basePrice);

    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);
    bool operator==(const Cargo&) const;

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

private:
    const std::string name_; 
    size_t amount_ {};
    size_t basePrice_ {}; 
};
