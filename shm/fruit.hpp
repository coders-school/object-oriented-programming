#pragma once
#include "cargo.hpp"
#include <cstddef>

class Fruit : public Cargo {

  size_t daysToExpiry_;

public:
  Fruit(std::string& name, size_t amount, size_t basePrice, size_t daysToExpiry);
  Fruit &operator+=(size_t amount);
  Fruit &operator-=(size_t amount);
  //Fruit &operator --(size_t basePrice);
  bool operator==(Fruit &fruit) const ;

  size_t getPrice() const override;
  std::string getName() const override;
  size_t getAmount() const override;
  size_t getBasePrice() const override;

  size_t nextDay() override;
};