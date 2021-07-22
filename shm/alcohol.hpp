#pragma once
#include "cargo.hpp"
#include <cstddef>

class Alcohol : public Cargo {

  size_t alcoholByVolume_{};
  const size_t maxAlcoholByVolume_{96};

public:
  Alcohol(std::string name, size_t amount, size_t alcoholByVolume);
  Cargo &operator+=(size_t amount);
  Cargo &operator-=(size_t amount);
  bool operator==(Cargo &cargo) const override;

  size_t getPrice() const override;
  std::string getName() const override;
  size_t getAmount() const override;
  size_t getBasePrice() const override;

  size_t nextDay() override;
};