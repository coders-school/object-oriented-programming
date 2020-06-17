#pragma once

#include <string>

class Cargo {
  private: 
     std::string name_;
     size_t amount_;
     size_t basePrice_;

  public: 
     Cargo();
     Cargo(size_t amount, std::string name, size_t basePrice) {}
     ~Cargo() {;} 

     std::string getName();
     size_t getAmount();
     size_t getBasePrice();
     bool operator==(Cargo& cargo);
};
