#include <string>

class Cargo {
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(std::string name, size_t amount, size_t basePrice);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo&);
    std::string Cargo::getName() const { return name_; }
    size_t Cargo::getAmount() const { return amount_; }
    size_t Cargo::getBasePrice() const { return basePrice_; }
};
