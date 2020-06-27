#pragma once
#include <string>
class Fruit : public Cargo {
public:
    //Override from Cargo
    Fruit(std::string name, size_t amount, size_t basePrice);
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Fruit& operator--();

private:
   size_t timeToSpoil_ {12};
   const size_t expiryDate_ {12};
};
