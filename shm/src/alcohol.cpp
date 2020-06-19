#include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name,
                 size_t amount,
                 size_t basePrice,
                 size_t percentage)
    : Cargo(name, amount, basePrice), percentage_(percentage) {}
