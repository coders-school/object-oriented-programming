#pragma once

#include "cargo.hpp"
//Class responsible for managing Fruit in the game.
class Fruit : public Cargo {
public:
   Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expirationDate, std::shared_ptr<Time> time); 
    ~Fruit() override;

    //Cargo& operator+=(size_t amount) override;
    //Cargo& operator-=(size_t amount) override;
    //bool operator==(const Cargo&) const override;
    Fruit& operator--();
    // Fruit& operator--(int);

    //Methods override from Cargo class.
    size_t getPrice() const override;
    //virtual std::string getName() const override { return name_; };
    //size_t getAmount() const override { return amount_; };
    //size_t getBasePrice() const override { return basePrice_; };

    size_t getExpirationDate() const { return expirationDate_; };
    size_t getPurchaseData() const { return purchaseDate_; };
  //  void setAmount(const size_t& amount) override { amount_ = amount;};

    void nextDay() override;

    std::shared_ptr<Cargo> clone(const size_t &) const;

    void setTime(const std::shared_ptr<Time>&) override;

    void detachingObserver() override;

protected:
    size_t expirationDate_;
    size_t purchaseDate_ = expirationDate_;
};
