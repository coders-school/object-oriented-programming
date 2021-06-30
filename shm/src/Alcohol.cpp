#include "shm/inc/Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage) 
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , percentage_(percentage)
{}

Alcohol::~Alcohol() override = default;


