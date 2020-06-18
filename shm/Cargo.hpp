#pragma once

#include <string>

class Cargo {
 public:
  Cargo& operator+=(size_t amount) {
    amount_ += amount;
    return *this;
  }
  Cargo& operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
  }
  Cargo() : amount_() {}

  friend bool operator==(const Cargo& lhs, const Cargo& rhs);
  friend bool operator!=(const Cargo& lhs, const Cargo& rhs);

 protected:
  std::string name_;
  size_t amount_;
  size_t basePrice_;
};

bool operator==(const Cargo& lhs, const Cargo& rhs) {
  return lhs.amount_ == rhs.amount_;
}

bool operator!=(const Cargo& lhs, const Cargo& rhs) {
  return lhs.amount_ != rhs.amount_;
}
