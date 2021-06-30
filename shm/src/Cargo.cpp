#include "inc/Cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice_) 
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
{}