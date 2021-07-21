#pragma once
#include "cargo.hpp"

enum class Rarity {
  common,
  rare,
  epic,
  legendary,
};

class Item : public Cargo {

size_t getPrice() const override;
std::string getName() const override;
size_t getAmount() const override;
size_t getBasePrice() const override;
Cargo& operator+=(size_t amount) override;
Cargo& operator-=(size_t amount) override
bool operator==(Cargo& cargo) const override;

// Metoda getPrice() powinna być adekwatnie wyliczana od poziomu rzadkości przedmiotu.

};