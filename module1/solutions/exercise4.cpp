#include <string>

class Cargo {
public:
    Cargo() = default;
    Cargo(size_t amount, std::string name, size_t basePrice)
        : name_(name), amount_(amount), basePrice_(basePrice)
    {}

    std::string getName() const { return name_; }
    size_t getAmount() const    { return amount_; }
    size_t getBasePrice() const { return basePrice_; }
    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(size_t amount) {
        amount_ -= amount;
        return *this;
    }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
