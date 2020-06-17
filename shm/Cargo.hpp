#include <string>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice)
        : name_(name), amount_(amount), basePrice_(basePrice) {}

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

    Cargo& operator+=(const size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t amount) {
        if (amount > amount_) {
            amount_ = 0;
            return *this;
        }
        amount_ -= amount;
        return *this;
    }
    bool operator==(const Cargo& cargo) {
        return (name_ == cargo.name_) && (amount_ == cargo.amount_) && (basePrice_ == cargo.basePrice_);
    }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
