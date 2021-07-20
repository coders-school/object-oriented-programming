#pragma once

#include "cargo.hpp"
//Class responsible for managing Fruit in the game.
class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expirationDate);
    ~Fruit() override {};

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
     bool operator==(const Cargo&) const;
    virtual Fruit& operator--();
    virtual Fruit operator--(int);

    //Methods override from Cargo class.
    virtual size_t getPrice() const override;
    virtual std::string getName() const override { return name_; };
    size_t getAmount() const override { return amount_; };
    size_t getBasePrice() const override { return basePrice_; };

    size_t getExpirationDate() const { return expirationDate_; };
    size_t getPurchaseData() const { return purchaseDate_; };

protected:
    size_t expirationDate_;
    size_t purchaseDate_ = expirationDate_;
};