#pragma once

#include <string>

class Cargo {
  private: 
     std::string name_;
     size_t amount_;
     size_t base_price_;

  public: 
     Cargo();
     Cargo(size_t amount, std::string name, size_t base_price) {}
     ~Cargo() {;} 

     std::string getName();
     size_t getAmount();
     size_t getBase_price();
     bool operator==(Cargo& cargo);

};
