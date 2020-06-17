#pragma once

#include <string>

class Cargo {
  private: 
     std::string name_;
     uint8_t amount_;
     uint8_t basePrice_;

  public: 
     Cargo();
     Cargo(uint8_t amount, std::string name, uint8_t basePrice) {}
     ~Cargo() {;} 

     std::string getName();
     uint8_t getAmount();
     uint8_t getBasePrice();
     bool operator==(Cargo& cargo);
};
