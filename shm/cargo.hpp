#pragma once

#include <string>

class Cargo {
   public:
    Cargo& operator+=(uint32_t amount);
    Cargo& operator-=(uint32_t amount);

   private:
    std::string name_;
    uint32_t amount_;
    uint32_t basePrice_;
};
