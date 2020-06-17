#pragma once

#include <string>

class Cargo {
   public:
    Cargo& operator+=(uint8_t amount);
    Cargo& operator-=(uint8_t amount);

   private:
    std::string name_;
    uint8_t amount_;
    uint8_t basePrice_;
};
