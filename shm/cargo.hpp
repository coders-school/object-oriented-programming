#pragma once
#include <cstddef>
#include <string>

// class to store cargos which will be used to sell bought and transport on ship
// in future will be used as base class to create specilised carogs like coal,
// wood, wool, etc.
class Cargo {
private:
  const std::string name_ {};
  size_t amount_ {};
  size_t basePrice_ {};

public:
  Cargo(const std::string &, size_t, size_t);

  // operators will be used to add, subtract and copare how many and  what we
  // have
  Cargo &operator+=(size_t amount);
  Cargo &operator-=(size_t amount);
  virtual bool operator==(Cargo &cargo) const = 0;


  /// simple getters
  virtual std::string getName() const = 0;
  virtual size_t getAmount() const = 0;
  virtual size_t getPrice() const = 0;
  virtual size_t getBasePrice() const = 0;

  size_t addAmount(size_t);
  size_t dellAmount(size_t);

};
