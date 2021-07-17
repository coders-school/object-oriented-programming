#include <string>
#include <memory>

// Interface class used to represent cargo carried by each ship
class Cargo {
private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    friend size_t operator+(size_t sum, const Cargo& cargo);

public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo&);
    const std::string& Cargo::getName() const { return name_; }
    size_t Cargo::getAmount() const { return amount_; }
    size_t Cargo::getBasePrice() const { return basePrice_; }
    friend size_t operator+(size_t sum, const Cargo& cargo);
};

size_t operator+(size_t sum, const std::shared_ptr<Cargo> & cargo){
    return sum + cargo->getAmount();
}
