#pragma once

#include <string>

class Cargo {
  private: 
     std::string name_;
     uint32_t amount_;
     uint32_t basePrice_;

  public: 
     Cargo();
     Cargo(uint32_t amount, std::string name, uint32_t basePrice) {}
     ~Cargo() {;} 

     std::string getName();
     uint32_t getAmount();
     uint32_t getBasePrice();
     bool operator==(Cargo& cargo);
};
