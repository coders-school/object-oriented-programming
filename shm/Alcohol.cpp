#include "Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t strength)
        : Cargo(name, amount, basePrice), strength_(strength){}