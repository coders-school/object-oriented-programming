#include "shm/inc/Fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice)
   : Cargo(name, amount, basePrice)
{}